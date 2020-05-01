/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filtres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 20:50:25 by erahimi           #+#    #+#             */
/*   Updated: 2020/03/10 20:50:26 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void   filtre(t_rt *rt)
{
    if (rt->f == MB_FILTRE)
        ft_filter_mb(rt->data);
    if(rt->f == SP_FILTRE)
        sepia_filtre(rt->data);
}
