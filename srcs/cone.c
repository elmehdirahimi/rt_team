/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:15:54 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 20:48:49 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"


static int		solution_cone(t_rt *rt, double all[7], double *dist, t_object *cone_temp)
{
	if (all[4] > -1e-4 && all[5] > -1e-4)
	{
		if (all[4] < all[5] && getColorFromTexture(rt, cone_temp, all[4]))
			*dist =  all[4];
		else
		{
			if (getColorFromTexture(rt, cone_temp, all[5]))
				*dist =  all[5];
		}
	}	
	else if (all[4] < 1e-4 && all[5] < 0.0)
		return (0);
	else
	{
		if (all[4] < all[5])
		{
			if (getColorFromTexture(rt, cone_temp, all[4]))
				*dist =  all[4];
		}
		else
		{
			if (getColorFromTexture(rt, cone_temp, all[5]))
				*dist =  all[5];
		}
	}
	if (*dist <= 1e-4  && getColorFromTexture(rt, cone_temp, *dist))
		return (0);
	return (1);
}


int				cone_intersection(t_rt *rt, t_object *cone_temp, double *dist)
{
	t_vect vect;
	double all[7];

	all[6] = tan(cone_temp->r);
	vect = soustraction(rt->cam.cam_ray.o, cone_temp->position);
	all[0] = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) - (1.0 + all[6] *
			all[6]) * pow(dot(rt->cam.cam_ray.d, cone_temp->direction), 2);
	all[1] = 2.0 * (dot(rt->cam.cam_ray.d, vect) - (1.0 + all[6] * all[6]) *
			dot(rt->cam.cam_ray.d, cone_temp->direction)
			* dot(vect, cone_temp->direction));
	all[2] = dot(vect, vect) - (1.0 + all[6] * all[6]) *
		dot(vect, cone_temp->direction) * dot(vect, cone_temp->direction);
	all[3] = all[1] * all[1] - 4.0 * all[0] * all[2];
	if (all[3] < 0.0)
		return (0);
	all[4] = (-all[1] - sqrt(all[3])) / (2.0 * all[0]);
	all[5] = (-all[1] + sqrt(all[3])) / (2.0 * all[0]);

	return (solution_cone(rt, all, dist, cone_temp));
}
/*
int  cone_intersection(t_rt *rt, t_object *cone_temp, double *dist)
{
    t_vect vect;
    double a;
    double b;
    double c;
    double delta;
    double t1;
    double t2;
    double k;

	cone_temp->t2 = 0;
    k = tan(cone_temp->r);
    vect = soustraction(rt->cam.cam_ray.o, cone_temp->position);
    a = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) - (1.0 + k * k) * dot(rt->cam.cam_ray.d, cone_temp->direction) * dot(rt->cam.cam_ray.d, cone_temp->direction);
    b = 2.0 * (dot(rt->cam.cam_ray.d, vect) - (1.0 + k * k) *  dot(rt->cam.cam_ray.d, cone_temp->direction) * dot(vect, cone_temp->direction));
    c = dot(vect, vect) - (1.0 + k * k) * dot(vect, cone_temp->direction) * dot(vect, cone_temp->direction);
    delta = b * b - 4.0 * a * c;
      if (delta >= 0.0)
     {
    t1 = (- b - sqrt(delta)) / (2.0 * a);
    t2 = (- b + sqrt(delta)) / (2.0 * a);
  //  light_inter(rt, t1);
   // light_inter(rt, t2);
  if (t2 > t1 && t1 > 1e-4 && getColorFromTexture(rt, cone_temp, t1))
     { *dist = t1;
	  cone_temp->t2 = 1;
	  }
    else
	{
		
      *dist = t2;
	}
    if(*dist >= 1e-4 && getColorFromTexture(rt, cone_temp, *dist))
     return (1);
     }
     return (0);
}*/
int GetAngleCone(t_object *cone_temp, t_vect p)
{
	cone_temp->txt->Um = (atan2(p.x, p.z) / (2.0 * M_PI));
	cone_temp->txt->Vm = (p.y + 5.0 /2 )/ 5.0;
	cone_temp->txt->Um -= floor(cone_temp->txt->Um);
	if(!cone_temp->txt->coup)
		cone_temp->txt->Vm -= floor(cone_temp->txt->Vm);
	else
	{
		if(cone_temp->txt->Vm > 1.0 || cone_temp->txt->Vm < 0.0)
			return(0);
	}
	return(1);
}