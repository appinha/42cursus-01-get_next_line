/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 20:01:39 by apuchill          #+#    #+#             */
/*   Updated: 2020/04/18 20:33:00 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tot_size;
	size_t	i;
	void	*dst;

	tot_size = size * count;
	if (!(dst = malloc(tot_size)))
		return (0);
	i = 0;
	while (i < tot_size)
	{
		((unsigned char *)dst)[i] = 0;
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + 1;
	if (!(s2 = (char *)malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		((unsigned char *)s2)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	return (s2);
}
