/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:24:19 by apuchill          #+#    #+#             */
/*   Updated: 2020/03/08 13:24:19 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# define READL_OK 1
# define EOF_RCHD 0
# define ERR_HPND -1

int		get_next_line(int fd, char **line);

/*
** Utils
*/

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

/*
** APAGAR
*/
/*
# define ARG_MAX			sysconf(_SC_ARG_MAX)
# define OPEN_MAX			FOPEN_MAX
# define MAIN(string)		"\033[1m\033[38;5;199m" string "\033[0m"
# define MAIN_1(string)		"\033[35m" string "\033[0m"
# define HEADER_1(string)	"\033[38;5;43m" string "\033[0m"
# define HEADER_2(string)	"\033[38;5;75m" string "\033[0m"
# define HIGHLIGHT(string)	"\033[38;5;191m" string "\033[0m"
*/
#endif
