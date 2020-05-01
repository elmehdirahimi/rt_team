/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:09:24 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/07 14:09:46 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] <= 122 && str[i] >= 97)
			str[i] -= 32;
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+' ||
				str[i] == '\t' || str[i] == '\n')
		{
			if (str[i + 1] <= 122 && str[i + 1] > 96)
				str[i + 1] -= 32;
		}
		i++;
	}
	return (str);
}
