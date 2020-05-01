/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_calcul.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:47:20 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 21:53:21 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_object	*intersection(t_rt *rt, double max)
{
	t_object	*temp;
	t_object *temp2;
	double		dist;
	t_object	*obj_affich;

	rt->t = max;
	temp = rt->object;
	obj_affich = NULL;
	while (temp)
	{
		temp2 = temp->compos;
		while (temp2)
		{
		if (inter(rt, temp2, &dist))
		{
			if (rt->t > dist)
			{
				rt->t = dist;
				obj_affich = temp2;
			}
		}
		temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (obj_affich);
}

void		ray_calcul(t_rt *rt, t_vect pixel_vect)
{
	t_object	*obj_affich;

	rt->cam.cam_ray.d = normale(soustraction(pixel_vect, rt->cam.cam_ray.o));
	obj_affich = intersection(rt, 800000.0);
	if (obj_affich && rt->t > 0.0)
	{
		put_pixel(rt, rt->x, rt->y, shading(rt, obj_affich));
	}
}

void		draw(t_rt *rt)
{
	t_vect	pixel_vect;

	ft_bzero((void *)rt->data, WIDHT * HEIGHT * 4);
	mlx_clear_window(rt->mlx_ptr, rt->win_ptr);
//	check_light(rt);
	rt->x = 0;
	while (rt->x <= WIDHT)
	{
		rt->y = 0;
		while (rt->y <= HEIGHT)
		{
			pixel_vect = addition(addition(rt->cam.center_corner,
					multiplication(rt->cam.u, rt->x * 2 * rt->cam.h / WIDHT)),
					multiplication(rt->cam.v, rt->y * 2 * rt->cam.h / WIDHT));
			ray_calcul(rt, pixel_vect);
			rt->y++;
		}
		rt->x++;
	}
	filtre(rt);
	mlx_put_image_to_window(rt->mlx_ptr, rt->win_ptr, rt->img_ptr, 0, 0);
}
