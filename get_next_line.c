/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:42 by apuchill          #+#    #+#             */
/*   Updated: 2020/04/17 20:12:50 by apuchill         ###   ########.fr       */
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

static size_t	ft_copy_buff(char **buff, long long i)
{
	char	*tmp;

	tmp = ft_strdup(*buff);
	ft_free_nl(&*buff);
	*buff = ft_substr(tmp, i + 1 , (ft_strlen(tmp) - i - 1));
}

static int		ft_buff2line(char **line, char **buff)
{
	long long	i;
	long long	j;
	char		tmp[ARG_MAX];

	while (*line[i] != '\0')
	{
		tmp[i] = *line[i];
		i++;
	}
	ft_free_nl(&*line);
	while (*buff[j] != '\n' && *buff[j] != '\0')
		tmp[i++] = *buff[j++];
	tmp[i] = 0;
	*line = ft_strdup(tmp);
	if (buff[j] == '\n' && buff[j + 1] != '\0')
	{
		ft_copy_buff(&*buff, j);
		return (1);
	}
	ft_free_nl(&*buff);
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
	ft_free_nl(&*line);
	return (ERR_HPND);
}
