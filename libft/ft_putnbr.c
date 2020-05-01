/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:22:39 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/07 14:23:02 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int size;
	int test;

	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb == -2147483648)
	{
		ft_putchar(50);
		nb = 147483648;
	}
	size = 1;
	test = nb;
	while ((test /= 10) != 0)
		size *= 10;
	while (size != 0)
	{
		test = nb / size;
		nb %= size;
		size /= 10;
		ft_putchar(test + 48);
	}
}
