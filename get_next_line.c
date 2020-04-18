/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:42 by apuchill          #+#    #+#             */
/*   Updated: 2020/04/18 19:08:16 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_free_null(char **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static void	ft_cpy_exc_buff(char **buff, long long j)
{
	long long	i;
	char		tmp[ARG_MAX];

	i = 0;
	if (buff[0][j] == '\0')
		ft_free_null(&*buff);
	else
	{
		while (buff[0][j] != '\0')
			tmp[i++] = buff[0][j++];
		tmp[i] = '\0';
		ft_free_null(&*buff);
		*buff = ft_strdup(tmp);
	}
}

static int		ft_buff2line(char **line, char **buff)
{
	long long	i;
	long long	j;
	char		tmp[ARG_MAX];

	i = 0;
	j = 0;
	while (line[0] != NULL && line[0][i] != '\0')
	{
		tmp[i] = line[0][i];
		i++;
	}
	ft_free_null(&*line);
	while (buff[0][j] != '\0' && buff[0][j] != '\n')
		tmp[i++] = buff[0][j++];
	tmp[i] = 0;
	*line = ft_strdup(tmp);
	if (buff[0][j] == '\n')
	{
		ft_cpy_exc_buff(&*buff, j + 1);
		return (1);
	}
	ft_free_null(&*buff);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*buff[OPEN_MAX];
	int			read_ret;
	int			status;

	if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup("")))
	{
		status = 0;
		while (status == 0)
		{
			if (buff[fd] == NULL && (buff[fd] = ft_calloc(BUFFER_SIZE + 1, 1)))
				read_ret = read(fd, buff[fd], BUFFER_SIZE);
			else
				read_ret = ft_strlen(buff[fd]);
			status = ft_buff2line(&*line, &buff[fd]);
			if (read_ret == 0)
				return (EOF_RCHD);
			if (read_ret < 0)
				break ;
		}
		if (status == 1)
			return (READL_OK);
	}
	ft_free_null(&*line);
	return (ERR_HPND);
}
