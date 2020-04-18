/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:42 by apuchill          #+#    #+#             */
/*   Updated: 2020/04/18 14:37:48 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strchr_i(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && c != s[i])
		i++;
	if (c == s[i])
		return (i);
	return (-1);
}

static void		ft_free_nl(char **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}

static int		ft_buff2line(char **line, char **buff)
{
	long long	i_pos;
	char		*tmp;

	tmp = ft_strjoin(*line, *buff);
	ft_free_nl(&*line);
	ft_free_nl(&*buff);
	if ((i_pos = ft_strchr_i(tmp, '\n')) > -1)
	{
		*line = ft_substr(tmp, 0, i_pos);
		if((ft_strlen(tmp) - i_pos) > 1)
			*buff = ft_substr(tmp, i_pos + 1 , (ft_strlen(tmp) - i_pos - 1));
		ft_free_nl(&tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(tmp);
		ft_free_nl(&tmp);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	static char	*buff[FOPEN_MAX];
	int			read_ret;
	int			status;

	if (fd >= 0 && line && BUFFER_SIZE > 0 && (*line = ft_strdup("")))
	{
		status = 0;
		while (status == 0)
		{
			if (buff[fd] == NULL && (buff[fd] = malloc(BUFFER_SIZE + 1)))
				read_ret = read(fd, buff[fd], BUFFER_SIZE);
			else
				read_ret = ft_strlen(buff[fd]);
			buff[fd][read_ret] = 0;
			status = ft_buff2line(&*line, &buff[fd]);
			if (read_ret == 0)
				return (EOF_RCHD);
			if (read_ret < 0)
				break ;
		}
		if (status == 1)
			return (READL_OK);
	}
	ft_free_nl(&*line);
	return (ERR_HPND);
}
