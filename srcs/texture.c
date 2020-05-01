/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:21:52 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/01 12:21:55 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int   GetAngle(t_object *obj , t_vect inter)
{
	if(obj->type == 1)
		return (GetAngleSphere(obj , inter));
	else if (obj->type == 2)
		return(GetAnglePlan(obj , inter));
	else if (obj->type == 3)
		return(GetAngleCylinder(obj , inter));
	else if (obj->type == 4)
		return(GetAngleCone(obj , inter));
	return (0);
}



int		getColorFromTexture(t_rt *rt, t_object *obj,  double t)
{
	int		i;
	int		j;
	t_vect inter;
	t_vect p;
	int c;


	inter = soustraction(obj->position ,addition(multiplication(rt->cam.cam_ray.d, t), rt->cam.cam_ray.o));
	//p = soustraction(obj->position,constrector(dot(inter,constrector(0.0 ,0.0, 1.0)), dot(inter, constrector(0.0 ,-1.0, 0.0)), dot(inter, constrector(1.0 ,0.0, 0.0))));
	 p = constrector(dot(inter,obj->repere.i), dot(inter, obj->repere.j), dot(inter, obj->repere.k));
	
	if(obj->coupe == 1)
		return (slice(obj,p));
	if(obj->tc == TEXTURE)
{		
	c = GetAngle(obj, p);
	i = obj->txt->Um * obj->txt->w;
	j = (1.0 - obj->txt->Vm) * obj->txt->h - 0.001;
	i = (i < 0) ? 0 : i;
	j = (j < 0) ? 0 : j;
	i = (i > obj->txt->w - 1) ? obj->txt->w - 1 : i;
	j = (j > obj->txt->h - 1) ? obj->txt->h - 1 : j;
	if (obj->txt->buf[j * obj->txt->w + i] == -16777216 || c == 0)
			return(0);
	obj->color.x = (obj->txt->buf[j * obj->txt->w + i] >> 16) & 0xFF;
	obj->color.y = (obj->txt->buf[j * obj->txt->w + i] >> 8) & 0xFF;
	obj->color.z = obj->txt->buf[j * obj->txt->w + i] & 0xFF;
}
	return (1);
}