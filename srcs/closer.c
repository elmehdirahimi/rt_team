/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 20:16:08 by erahimi           #+#    #+#             */
/*   Updated: 2020/02/23 21:34:27 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void		ft_free_lights(t_light **light)
{
	t_light	*l;
	t_light	*tmp;

	l = *light;
	while (l != NULL)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

void		ft_free_object(t_object **object)
{
	t_object	*l;
	t_object	*tmp;

	l = *object;
	while (l != NULL)
	{
		tmp = l->next;
		free(l);
		l = tmp;
	}
}

int			rt_close2(t_rt **rt)
{
	free(*rt);
	ft_putendl("error reading");
	exit(0);
	return (1);
}

int			rt_close1(t_rt **rt)
{
	ft_free_object(&(*rt)->object);
	ft_free_lights(&(*rt)->light);
	free(*rt);
	ft_putendl("error parsing");
	exit(0);
	return (1);
}

int			rt_close(t_rt **rt)
{
	ft_free_object(&(*rt)->object);
	ft_free_lights(&(*rt)->light);
	mlx_destroy_image((*rt)->mlx_ptr, (*rt)->img_ptr);
	(*rt)->img_ptr = NULL;
	mlx_destroy_window((*rt)->mlx_ptr, (*rt)->win_ptr);
	(*rt)->win_ptr = NULL;
	(*rt)->mlx_ptr = NULL;
	free(*rt);
	exit(0);
	return (1);
}
