/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mb_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:56:19 by erahimi           #+#    #+#             */
/*   Updated: 2020/03/10 12:56:20 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int r(int c)
{
    return ((c >> 16) & 0xFF);
}
int g(int c)
{
    return ((c >> 8) & 0xFF);
}
int b(int c)
{
    return (c & 0xFF);
}

int rgb_int(int r, int g, int b)
{
    return ((r << 16) | (g << 8) | b);
}

t_vect int_rgb(int c)
{
	return (constrector(r(c), g(c), b(c)));
}
static void		mb_loop(int *d, t_loop *loop, t_loop *filter, t_vect *c)
{
	t_loop	img;

	img.i = (int)(loop->i - FILTER_MB_W / 2 + filter->i + WIDHT)
		% WIDHT;
	img.j = (int)(loop->j - FILTER_MB_H / 2 + filter->j + HEIGHT)
		% HEIGHT;
	c->x += r(d[img.j * WIDHT + img.i])
		* (filter->i == filter->j ? 1 : 0);
	c->y += g(d[img.j * WIDHT + img.i])
		* (filter->i == filter->j ? 1 : 0);
	c->z += b(d[img.j * WIDHT + img.i])
		* (filter->i == filter->j ? 1 : 0);
}

void			ft_filter_mb(int *data)
{
	t_loop	loop;
	t_loop	filter;
	t_vect		c;

	loop.i = -1;
	while (++loop.i < WIDHT)
	{
		loop.j = -1;
		while (++loop.j < HEIGHT)
		{
			c = constrector(0.0, 0.0, 0.0);
			filter.j = -1;
			while (++filter.j < FILTER_MB_H)
			{
				filter.i = -1;
				while (++filter.i < FILTER_MB_W)
					mb_loop(data, &loop, &filter, &c);
				data[loop.j * (int)WIDHT + loop.i] =
					rgb_int(clamp((int)(c.x / 9.0), 255.0, 0.0),
							clamp((int)(c.y / 9.0), 255.0, 0.0),
							clamp((int)(c.z / 9.0), 255.0, 0.0));
			}
		}
	}
}
