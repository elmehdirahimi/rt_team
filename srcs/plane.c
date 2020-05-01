/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:36:12 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/22 01:54:19 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		plane_intersection(t_rt *rt, t_object *plane_temp, double *dist)
{
	t_vect	vect;
	double	a;
	double	b;

	vect = soustraction(rt->cam.cam_ray.o, plane_temp->position);
	a = -dot(vect, plane_temp->direction);
	b = dot(rt->cam.cam_ray.d, plane_temp->direction);
	*dist = a / b;
	if(*dist >= 1e-4 && getColorFromTexture(rt, plane_temp, *dist))
		return (1);
	return (0);
}
int  GetAnglePlan(t_object *plane_temp , t_vect p)
{
	plane_temp->txt->Um = p.x * 0.01;
	plane_temp->txt->Vm = p.y * 0.01;
	if(!plane_temp->txt->coup)
		plane_temp->txt->Um -= floor(plane_temp->txt->Um);
	else
	{
		if(plane_temp->txt->Um > 1.0 || plane_temp->txt->Um < 0.0)
			return(0);
	}
	if(!plane_temp->txt->coup)
		plane_temp->txt->Vm -= floor(plane_temp->txt->Vm);
	else
	{
		if(plane_temp->txt->Vm > 1.0 || plane_temp->txt->Vm < 0.0)
			return(0);
	}
	return(1);
}