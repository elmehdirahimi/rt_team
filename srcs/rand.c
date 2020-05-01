/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:21:12 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/29 13:21:13 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

double		ft_rand3dto1d(t_vect value, t_vect dot_dir)
{
	t_vect	small_value;
	double		random;

	small_value = constrector(cos(value.x), cos(value.y), cos(value.z));
	random = dot(small_value, dot_dir);
	random = ft_frac(sin(random));
	return (random);
}


double		ft_rand1dto1d(double value, double mutator)
{
	return (ft_frac(sin(value + mutator) * 143758.5453));
}

t_vect	ft_rand1dto3d(double value)
{
	return (constrector(
				ft_rand1dto1d(value, 3.9812),
				ft_rand1dto1d(value, 7.1536),
				ft_rand1dto1d(value, 5.7241)));
}
t_vect	ft_rand3dto3d(t_vect value)
{
	return (constrector(
				ft_rand3dto1d(value, constrector(102.989, 708.233, 370.719)),
				ft_rand3dto1d(value, constrector(390.346, 110.135, 830.155)),
				ft_rand3dto1d(value, constrector(730.156, 502.235, 90.151))));
}

double rand1dTo1d(double value, double mutator)
{
	double random = ft_frac(sin(value + mutator) * 143758.5453);
	return random;
}

t_vect rand1dTo3d(double value)
{
	return constrector(
		rand1dTo1d(value, 3.9812),
		rand1dTo1d(value, 7.1536),
		rand1dTo1d(value, 5.7241)
	);
}