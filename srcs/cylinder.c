/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 20:53:11 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/22 01:51:44 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"


int		cylinder_intersection(t_rt *rt, t_object *plane_temp, double *dist)
{
	t_vect	vect;
	double	all[6];

	plane_temp->t2 = 0;
	vect = soustraction(rt->cam.cam_ray.o, plane_temp->position);
	all[0] = dot(rt->cam.cam_ray.d, rt->cam.cam_ray.d) -
		dot(rt->cam.cam_ray.d, plane_temp->direction) *
		dot(rt->cam.cam_ray.d, plane_temp->direction);
	all[1] = 2.0 * (dot(rt->cam.cam_ray.d, vect) -
	dot(rt->cam.cam_ray.d, plane_temp->direction) *
	dot(vect, plane_temp->direction));
	all[2] = dot(vect, vect) - dot(vect, plane_temp->direction)
	* dot(vect, plane_temp->direction) - plane_temp->r * plane_temp->r;
	all[3] = all[1] * all[1] - 4.0 * all[0] * all[2];
	if (all[3] >= 0.0)
	{
		all[4] = (-all[1] - sqrt(all[3])) / (2.0 * all[0]);
		all[5] = (-all[1] + sqrt(all[3])) / (2.0 * all[0]);
		if (all[5] > all[4] && all[4] >= 1e-4 && getColorFromTexture(rt, plane_temp, all[4]))
			*dist = all[4];
		else
		{
			plane_temp->t2 = 1;
			*dist = all[5];
		}
		if(*dist >= 1e-4 && getColorFromTexture(rt, plane_temp, *dist))
			return (1);
	}
	return (0);
}

int GetAngleCylinder(t_object *plane_temp , t_vect p)
{
	plane_temp->txt->Um = (atan2(p.x, p.z) / (2.0 * M_PI));
	plane_temp->txt->Vm = (p.y + plane_temp->txt->hi /2 )/ plane_temp->txt->hi;
	plane_temp->txt->Um -= floor(plane_temp->txt->Um);
	if(!plane_temp->txt->coup)
		plane_temp->txt->Vm -= floor(plane_temp->txt->Vm);
	else
	{
		if(plane_temp->txt->Vm > 1.0 || plane_temp->txt->Vm < 0.0)
			return(0);
	}
	return(1);
}
