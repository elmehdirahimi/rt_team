/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 01:19:41 by ibel-kha          #+#    #+#             */
/*   Updated: 2020/02/22 01:42:49 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

double	clamp(double v, double max, double min)
{
	if (v < min)
		v = min;
	else if (v > max)
		v = max;
	return (v);
}

t_vect  t(t_object *o, t_vect d, t_vect vect)
{
	if (o->type == 2 || o->t2 == 1)
	{
	if (dot(d, vect) > 1e-5)
			return (multiplication(vect, -1.0));
	}
	return (vect);
}

void  print_vect(t_vect vect)
{
	printf("(%f,%f,%f)\n",vect.x,vect.y,vect.z);
}
double	ft_frac(double value)
{
	return (value - floor(value));
}