/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:10:16 by hbouchak          #+#    #+#             */
/*   Updated: 2019/04/07 14:10:43 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	int		size;

	size = -1;
	i = 0;
	while (dest[i])
	{
		size++;
		i++;
	}
	i = 0;
	while (src[i])
	{
		dest[size + i + 1] = src[i];
		i++;
	}
	dest[size + i + 1] = '\0';
	return (dest);
}
