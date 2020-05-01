/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouklich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 21:51:53 by oouklich          #+#    #+#             */
/*   Updated: 2019/12/29 19:23:46 by oouklich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int			load_texture(t_rt *rt,t_object *obj, char *path)
{

		obj->txt->img = mlx_xpm_file_to_image(rt->mlx_ptr, path, &obj->txt->w,&obj->txt->h);
		if (!obj->txt->img)
			return (0);
		obj->txt->buf = (int *)mlx_get_data_addr(obj->txt->img, &rt->bpp,&rt->size_line, &rt->endian);
	return (1);
}