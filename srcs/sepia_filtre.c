/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia_filtre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:58:24 by erahimi           #+#    #+#             */
/*   Updated: 2020/03/10 20:58:28 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

static int		sepia(t_vect c)
{
	t_vect		v;

	v.x = clamp((c.x * .393) + (c.y * .769) + (c.z * .189), 255.0, 0.0);
	v.y = clamp((c.x * .349) + (c.y * .686) + (c.z * .168), 255.0, 0.0);
	v.z = clamp((c.x * .272) + (c.y * .534) + (c.z * .131), 255.0, 0.0);
	return (rgb_int(v.x, v.y, v.z));
}

void  sepia_filtre(int *data)
{
    int i;

    i = 0;
    while(i < (WIDHT * HEIGHT))
    {
       data[i] = sepia(int_rgb(data[i]));
        i++;
    }
}