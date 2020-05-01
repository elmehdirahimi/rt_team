/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 22:50:47 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/06 22:51:52 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		nbr;
	int		test;

	test = 0;
	i = 0;
	nbr = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
				str[i] == '\v' || str[i] == '\f' || str[i] == ' ') && str[i])
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			test++;
		i++;
	}
	while ((*(str + i) >= '0') && (*(str + i) <= '9'))
	{
		nbr = nbr * 10 + *(str + i) - 48;
		i++;
	}
	if (test == 1)
		return (-nbr);
	return (nbr);
}
