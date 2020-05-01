/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   voronoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:40 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/27 20:04:45 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"



t_vect	ft_vfloor(t_vect v)
{
	return (constrector(floor(v.x), floor(v.y), floor(v.z)));
}


static void		ft_voronoi_1(t_cell *c, t_vect value)
{
	t_cell		tmp;
	t_vect	cellposition;
	int i,j,k;

	i = -2;
	while (++i <= 1)
	{
		j = -2;
		while (++j <= 1)
		{
			k = -2;
			while (++k <= 1)
			{
				tmp.base = c->base;
				tmp.closest = addition(c->base,constrector(i, j, k));
				cellposition = addition(tmp.closest, ft_rand3dto3d(tmp.closest));
				tmp.toclosest = soustraction(cellposition, value);
				tmp.mindisttocell = module(tmp.toclosest);
				if (tmp.mindisttocell < c->mindisttocell)
					*c = tmp;
			}
		}
	}
}


static t_vect	ft_voronoi(t_vect value)
{
	t_cell	c;
	double	minedgedistance;
	double	random;
	c.base = ft_vfloor(value);
	c.mindisttocell = 10;
	ft_voronoi_1(&c, value);
	minedgedistance = 10;
	random = ft_rand3dto1d(c.closest,constrector(12.9898, 78.233, 37.719));
	return (ft_rand1dto3d(random));
}

t_vect			voronoi_noise(t_vect p)
{
	
	return (multiplication(ft_voronoi(multiplication(p, 1.0)), 255.0));
}
