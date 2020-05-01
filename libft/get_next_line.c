/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 21:10:00 by hbouchak          #+#    #+#             */
/*   Updated: 2019/07/07 21:30:49 by hbouchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_1(char **save, char *buf)
{
	char *tmp;

	tmp = ft_strdup(*save);
	free(*save);
	*save = ft_strjoin(tmp, buf);
	free(tmp);
}

void	ft_2(char **line, char **save, int i)
{
	char *tmp;

	tmp = ft_strdup(*save);
	*line = ft_strsub(*save, 0, i);
	free(*save);
	if (tmp[i] == '\0')
		*save = ft_strdup("");
	else
		*save = ft_strdup(tmp + i + 1);
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[4864];
	char			*buf;
	int				nbr_oct;
	int				i;

	i = 0;
	if (!(buf = ft_strnew(BUFF_SIZE + 1)) ||
			fd == -1 || !line || read(fd, buf, 0) < 0)
		return (FREE(buf, -1));
	if (save[fd] == NULL)
		save[fd] = ft_strnew(1);
	while ((nbr_oct = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nbr_oct] = '\0';
		ft_1(&save[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if ((ft_strlen(save[fd]) == 0) && (nbr_oct == 0))
		return (FREE(buf, 0));
	while (save[fd][i] != '\0' && save[fd][i] != '\n')
		i++;
	ft_2(line, &save[fd], i);
	return (FREE(buf, 1));
}
