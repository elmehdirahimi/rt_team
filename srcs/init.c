/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:11:42 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 21:50:44 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static void corner_help(t_rt *rt)
{
	t_vect tmp1;
	t_vect tmp2;
	t_vect tmp3;

	tmp1 = soustraction(rt->cam.cam_ray.o, rt->to);
	tmp2 = multiplication(rt->cam.v, rt->cam.h);
	tmp3 = multiplication(rt->cam.u, rt->cam.w);
	rt->cam.center_corner = soustraction(soustraction(tmp1, tmp2), tmp3);
}

void corner(t_rt *rt)
{
	rt->cam.w = tan((60.0 * M_PI / 180.0) / 2.0) * 1.0;
	rt->cam.h = rt->cam.w;
	rt->up = normale(constrector(0.0, 1.0, 0.0));
	rt->to = normale(soustraction(rt->cam.cam_ray.o, rt->cam.look_at));
	if (equal(rt->up, rt->to) == 1)
	{
		rt->cam.u = constrector(1.0, 0.0, 0.0);
		rt->cam.v = constrector(0.0, 0.0, 1.0);
	}
	else
	{
		if (equal(rt->up, rt->to) == 2)
		{
			rt->cam.u = constrector(-1.0, 0.0, 0.0);
			rt->cam.v = constrector(0.0, 0.0, 1.0);
		}
		else
		{
			rt->cam.u = cross(rt->up, rt->to);
			rt->cam.v = cross(rt->cam.u, rt->to);
		}
	}
	corner_help(rt);
}

static void object_init(t_rt *rt)
{
	t_object *temp;

	temp = rt->object;
	while (temp)
	{
		if (temp->type == 1) // pour sphere
		{
			temp->direction = constrector(0.0, 0.0, 1.0);
			temp->rotation = constrector(0.0, 20.0, 0.0);
		}
		if (temp->type == PLANE) // pour plan
		{
			temp->limitz = 12.5;
			temp->limitx = 12.5;
		}
		temp->color.x = clamp(temp->color.x, 255.0, 0);
		temp->color.y = clamp(temp->color.y, 255.0, 0);
		temp->color.z = clamp(temp->color.z, 255.0, 0);
		temp->rotation = constrector(clamp(temp->rotation.x, 360.0, 0.0) *
										 M_PI / 180.0,
									 clamp(temp->rotation.y, 360.0, 0.0) * M_PI / 180.0,
									 clamp(temp->rotation.z, 360.0, 0.0) * M_PI / 180.0);
		temp->repere = set_repere(temp->direction);
		project(&(temp->repere.i), temp->rotation);
		project(&(temp->repere.j), temp->rotation);
		project(&(temp->repere.k), temp->rotation);
		project(&(temp->direction), temp->rotation);
		temp->position = addition(temp->position, temp->translation);

		temp->limit = 1.5;
		add_compos(temp);
		temp = temp->next;
	}
}

void param_init(t_rt *rt)
{
	t_light *t;

	rt->cam.cam_ray.o =
		addition(rt->cam.cam_ray.o, rt->cam.cam_ray.translation);
	t = rt->light;
	while (t)
	{
		t->color = constrector(clamp(t->color.x, 255.0, 0),
							   clamp(t->color.y, 255.0, 0), clamp(t->color.z, 255.0, 0));
		t->position = addition(t->position, t->translation);
		t = t->next;
	}
	object_init(rt);
}

void init_perlin(t_rt *rt)
{
	int i;

	if (!(rt->ran = (t_vect *)malloc(256 * sizeof(t_vect))))
		exit(0);
	i = 0;
	while (i < 256)
	{
		rt->ran[i].x = rand() % 255;
		rt->ran[i].y = rand() % 255;
		rt->ran[i].z = rand() % 255;
		rt->ran[i] = normale(rt->ran[i]);
		i++;
	}
}

void initialize(t_rt *rt, char *argv)
{

	rt->mlx_ptr = mlx_init();
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, WIDHT, HEIGHT, argv);
	rt->img_ptr = mlx_new_image(rt->mlx_ptr, WIDHT, HEIGHT);
	rt->data = (int *)mlx_get_data_addr(rt->img_ptr, &(rt->bpp),
										&(rt->size_line), &(rt->endian));
	/*if (!load_texture(rt, "xpm/7.xpm"))
	{
		ft_putendl("error : failed to load texture");
		exit (0);
	}*/
	//param_init(rt);
	init_perlin(rt);
}
