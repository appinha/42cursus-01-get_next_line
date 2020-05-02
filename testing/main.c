/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:31:30 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/02 13:44:16 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define MAIN(string)		"\033[1m\033[38;5;199m" string "\033[0m"
#define MAIN_1(string)		"\033[35m" string "\033[0m"
#define HEADER_1(string)	"\033[38;5;43m" string "\033[0m"
#define HEADER_2(string)	"\033[38;5;75m" string "\033[0m"
#define HIGHLIGHT(string)	"\033[38;5;191m" string "\033[0m"

void	test(int fd)
{
	char	*line;
	int		ret;
	int		i;

	line = NULL;
	printf("> fd = %d\n", fd);
	i = 1;
	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		printf(HEADER_2("• Line n.%d ") HEADER_1("[RET=%d]: ") "\"%s\"\n", i, ret, line);
		free(line);
		line = NULL;
		i++;
	}
	close(fd);

}

int		main(void)
{
	printf(MAIN("=== • Program started • ===\n"));

	printf(MAIN_1("=== empty file ===\n"));
	int	fda;
	fda = open("txt_files/t_empty.txt", O_RDONLY);
	test(fda);

	printf(MAIN_1("=== \\n file ===\n"));
	int	fdb;
	fdb = open("txt_files/t_n.txt", O_RDONLY);
	test(fdb);

	printf(MAIN_1("=== Le Petit Prince ===\n"));
	int	fdc;
	fdc = open("txt_files/t_ptiprinc.txt", O_RDONLY);
	test(fdc);

	printf(MAIN("=== • Program ended • ===\n\n"));
}
