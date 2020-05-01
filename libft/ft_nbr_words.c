/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:18:44 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/07 15:19:05 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_words(char const *str, char c)
{
	int		nbr;
	int		i;

	nbr = 0;
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			i = i + ft_word_size(str, c, i);
			nbr++;
		}
		else
			i++;
	}
	return (nbr);
}
