/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:18:01 by ibel-kha          #+#    #+#             */
/*   Updated: 2020/02/22 01:25:11 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_vect	addition(t_vect vect1, t_vect vect2)
{
	t_vect	vect;

	vect.x = vect1.x + vect2.x;
	vect.y = vect1.y + vect2.y;
	vect.z = vect1.z + vect2.z;
	return (vect);
}

t_vect	soustraction(t_vect vect1, t_vect vect2)
{
	t_vect	vect;

	vect.x = vect1.x - vect2.x;
	vect.y = vect1.y - vect2.y;
	vect.z = vect1.z - vect2.z;
	return (vect);
}

t_vect	multiplication(t_vect vect1, double x)
{
	t_vect	vect;

	vect.x = vect1.x * x;
	vect.y = vect1.y * x;
	vect.z = vect1.z * x;
	return (vect);
}

double	dot(t_vect vect1, t_vect vect2)
{
	double d;

	d = vect1.x * vect2.x + vect1.y * vect2.y + vect1.z * vect2.z;
	return (d);
}

double	module(t_vect vect)
{
	return (sqrt(dot(vect, vect)));
}
