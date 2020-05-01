/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:55:03 by erahimi           #+#    #+#             */
/*   Updated: 2020/03/05 18:55:04 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_vect		get_color(t_rt *rt, t_object *obj)
{
   t_vect inter;
    t_vect p;

    if (obj->tc == COLOR || obj->tc == TEXTURE)
        return (obj->color);
    inter = addition(multiplication(rt->cam.cam_ray.d, rt->t), rt->cam.cam_ray.o);
    p = soustraction(obj->position , 
    constrector(dot(inter,constrector(1.0 ,0.0, 0.0)), 
    dot(inter, constrector(0.0 ,1.0, 0.0)), dot(inter, constrector(0.0 ,0.0, -1.0))));
    //p = create_v(dot(r->obj->inter,obj->repere.i), dot(r->obj->inter, obj->repere.j), dot(r->obj->inter, obj->repere.k));
   
    if (obj->tc == VORONOI)
        return(voronoi_noise(p));
    if (obj->tc == PERLIN)
       return(perlin(rt->ran, p, obj));
    return (constrector(0.0, 0.0, 0.0));
}