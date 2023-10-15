/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_dimensions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:28:19 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/15 14:23:38 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map_dimensions(char *filename, int *map_width, int *map_height)
{
	int	fd;

	*map_height = 0;
	*map_width = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (!check_row_per_row(fd, map_width, map_height))
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	check_row_per_row(int fd, int *map_width, int *map_height)
{
	int		row_length;
	char	*next_line;
	char	**one_row;

	next_line = gnl_no_newline(fd);
	while (next_line)
	{
		// ft_printf("next line is: $%s$\n", next_line);
		(*map_height)++;
		one_row = ft_split_str(next_line, " ");
		if (!one_row)
			return (0);
		row_length = ft_arr_len_char(one_row);
		// ftrintf("map height: $%d$\n", *map_height);
		// ft_printf("map width: $%d$\n", *map_width);
		// ft_printf("row length: $%d$\n", row_length);
		// ft_printf("\n\n\n");
		if (!check_row_against_prev(row_length, *map_width))
		{
			free(next_line);
			free_str_arr_null(one_row);
			return (0);
		}
		if(row_length > 0)
			*map_width = row_length;
		free_str_arr_null(one_row);
		free(next_line);
		next_line = gnl_no_newline(fd);
	}
	return (1);
}

int	check_row_against_prev(int row_length, int map_width)
{
	if (map_width == 0 || row_length == 0)
		return (1);
	if (row_length != map_width)
		return (0);
	return (1);
}

char	*gnl_no_newline(int fd)
{
	char	*next_line;
	char	*tmp;
	int		index_newline;

	next_line = get_next_line(fd);
	if (next_line)
	{
		index_newline = ft_str_chr_index(next_line, '\n');
		if (index_newline >= 0)
		{
			tmp = next_line;
			next_line = ft_substr(tmp, 0, index_newline);
			free(tmp);
		}
	}
	return (next_line);
}
