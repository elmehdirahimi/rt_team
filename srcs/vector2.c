/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:19:06 by ibel-kha          #+#    #+#             */
/*   Updated: 2020/02/22 01:26:01 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

t_vect	normale(t_vect vect)
{
	return (multiplication(vect, 1 / module(vect)));
}

t_vect	constrector(double x, double y, double z)
{
	t_vect vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}

t_vect	cross(t_vect vect1, t_vect vect2)
{
	t_vect vect;

	vect.x = vect1.y * vect2.z - vect1.z * vect2.y;
	vect.y = vect1.z * vect2.x - vect1.x * vect2.z;
	vect.z = vect1.x * vect2.y - vect1.y * vect2.x;
	return (vect);
}

t_vect	division(t_vect vect1, t_vect vect2)
{
	t_vect vect;

	vect.x = vect1.x / vect2.x;
	vect.y = vect1.y / vect2.y;
	vect.z = vect1.z / vect2.z;
	return (vect);
}

int		equal(t_vect vect1, t_vect vect2)
{
	if (vect1.y == vect2.y)
		return (1);
	if (vect1.y == -vect2.y)
		return (2);
	return (0);
}
