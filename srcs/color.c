/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:34:42 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 20:43:12 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

double		diffuse(t_rt *rt, t_object *sphere, t_light *temp, int choix)
{
	double	facing_ratio;
	t_vect	p;
	t_vect	ligth_d_norm;

	p = addition(rt->cam.cam_ray.o, multiplication(rt->cam.cam_ray.d, rt->t));
	ligth_d_norm = normale(soustraction(temp->position, p));
	if (choix == 1)
		facing_ratio = dot(get_normal(p, sphere, rt), ligth_d_norm);
	else
		facing_ratio = dot(get_reflected(p, ligth_d_norm, sphere, rt),
				rt->cam.cam_ray.d);
	if (facing_ratio < 0.0)
		facing_ratio = 0.0;
	if (choix == 1)
		return (facing_ratio * 0.8);
	return (pow(facing_ratio, 44.0));
}

int			swap(t_rt *rt, t_light *temp)
{
	t_object	*x;

	rt->temp_o = constrector(rt->cam.cam_ray.o.x,\
			rt->cam.cam_ray.o.y, rt->cam.cam_ray.o.z);
	rt->temp_d = constrector(rt->cam.cam_ray.d.x,\
			rt->cam.cam_ray.d.y, rt->cam.cam_ray.d.z);
	rt->t3 = rt->t;
	rt->cam.cam_ray.o = addition(rt->cam.cam_ray.o,\
			multiplication(rt->cam.cam_ray.d, rt->t));
	rt->cam.cam_ray.d = normale(soustraction(temp->position,\
				rt->cam.cam_ray.o));
	rt->max = module(soustraction(temp->position, rt->cam.cam_ray.o));
	x = intersection(rt, rt->max);
	rt->cam.cam_ray.o = rt->temp_o;
	rt->cam.cam_ray.d = rt->temp_d;
	if(rt->t -1e-5 > rt->max || rt->max > rt->t + 1e-5)
		return (0);
	rt->t = rt->t3;
	return (x ? 0 : 1);
}

t_vect		diffuse_clac(t_rt *rt, t_vect df, t_object *o, t_light *l, t_vect c)
{
	t_vect	d;

	d = addition(df, multiplication(constrector(c.x *
			(l->color.x / 255.0), c.y *
			(l->color.y / 255.0), c.z *
			(l->color.z / 255.0)),
			diffuse(rt, o, l, 1)));
	return (d);
}

int			shading(t_rt *rt, t_object *sphere)
{
	t_vect	all[4];
	t_vect	color;
	t_light	*temp;

	all[2] = constrector(0, 0, 0);
	all[3] = constrector(0, 0, 0);
	color = get_color(rt, sphere);
	all[1] = multiplication(color, 0.15);
	temp = rt->light;
	while (temp)
	{
		if (swap(rt, temp))
		{
			all[2] = diffuse_clac(rt, all[2], sphere, temp, color);
			all[3] = addition(all[3], multiplication(temp->color,
						diffuse(rt, sphere, temp, 2)));
		}
		temp = temp->next;
	}
	color = addition(addition(all[1], all[2]), all[3]);
	color = constrector(clamp(color.x, 255.0, 0.0),\
			clamp(color.y, 255.0, 0.0), clamp(color.z, 255.0, 0.0));
	return (((int)color.x << 16) | ((int)color.y << 8) | (int)color.z);
}

/*
t_vect  diffuse_clac(t_rt *rt,t_vect df,t_object *o, t_light *l)
{
	t_vect d;
	
	d = addition(df,multiplication(constrector(o->color.x * (l->color.x / 255.0),
	 	o->color.y * (l->color.y / 255.0),o->color.z * (l->color.z / 255.0)),
	 	 diffuse(rt, o,l, 1)));
	return(d);
}

int  shading(t_rt *rt, t_object* sphere)
{
	t_vect all[4];
	t_vect color;
	t_light *temp;

	all[2] = constrector(0, 0 ,0);
	all[3] = constrector(0, 0 ,0);
	color = sphere->color;
	all[1] =  multiplication(color, 0.15);
	temp = rt->light;
	while(temp)
	{
		if(swap(rt, temp))
		{	
			all[2] = diffuse_clac(rt,all[2],sphere, temp);
			all[3] = addition(all[3], multiplication(temp->color, diffuse(rt,sphere,temp, 2)));
		}
		temp = temp->next;     
	}
	color =  addition(addition(all[1],all[2]), all[3]);
	color = constrector(clamp(color.x, 255.0, 0.0),\
	 clamp(color.y, 255.0, 0.0), clamp(color.z, 255.0, 0.0));
	return (((int)color.x << 16) | ((int)color.y << 8) | (int)color.z );
}*/