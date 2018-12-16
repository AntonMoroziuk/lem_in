/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:52:16 by amoroziu          #+#    #+#             */
/*   Updated: 2018/11/06 09:05:31 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_line(char **files, int fd, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (files[fd][i] && files[fd][i] != '\n')
		i++;
	if (files[fd][i] == '\n')
	{
		MALLOCCHECK_INT((*line = ft_strsub(files[fd], 0, i)));
		temp = files[fd];
		MALLOCCHECK_INT((files[fd] = ft_strdup(files[fd] + i + 1)));
		free(temp);
	}
	else
	{
		MALLOCCHECK_INT((*line = ft_strdup(files[fd])));
		ft_strdel(&(files[fd]));
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*files[4863];
	int			rs;
	char		*buff;
	char		*temp;

	if (fd < 0 || line == NULL)
		return (-1);
	MALLOCCHECK_INT((buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))));
	while ((rs = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rs] = '\0';
		if (!files[fd])
			files[fd] = ft_strnew(1);
		temp = files[fd];
		files[fd] = ft_strjoin(files[fd], buff);
		free(temp);
		if (ft_strchr(files[fd], '\n'))
			break ;
	}
	ft_strdel(&buff);
	if (rs < 0)
		return (-1);
	if (rs == 0 && (files[fd] == NULL || files[fd][0] == '\0'))
		return (0);
	return (new_line(files, fd, line));
}
