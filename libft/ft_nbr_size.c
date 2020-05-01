/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:17:53 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/07 15:18:17 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_size(int *n, int *test, int *str_size)
{
	int		size;
	int		copy;

	copy = *n;
	*test = 0;
	*str_size = 0;
	if (copy < 0)
	{
		*n *= (-1);
		copy *= (-1);
		(*test)++;
		(*str_size)++;
	}
	size = 1;
	while ((copy /= 10) != 0)
	{
		size *= 10;
		(*str_size)++;
	}
	return (size);
}
