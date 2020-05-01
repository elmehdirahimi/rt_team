/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:43:35 by hbouchak          #+#    #+#             */
/*   Updated: 2020/01/21 16:43:43 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **ptr, size_t old, size_t len)
{
	void	*real;

	real = malloc(len);
	ft_memset(real, 0, len);
	if (real)
		ft_memcpy(real, *ptr, old);
	if (*ptr)
		free(*ptr);
	return (real);
}
