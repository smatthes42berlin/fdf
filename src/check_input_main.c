/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:41:34 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/15 11:37:08 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_input_main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("Error: please only provide exactly one argument.\n");
		return (0);
	}
	if (!check_file_extension(argv[1]))
	{
		ft_printf("Error: wrong extension of map.\n");
		return (0);
	}
	if (!map_can_be_opened(argv[1]))
	{
		ft_printf("Error: map-file cannot be opened.\n");
		return (0);
	}
	if (!map_is_ascii(argv[1]))
	{
		ft_printf("Error: map is no ascii file or");
		ft_printf(" does not contain any bytes.\n");
		return (0);
	}
	return (1);
}

int	check_file_extension(char *filename)
{
	char	**splitted;
	int		split_length;
	char	*extension;

	if (!filename || ft_strlen(filename) < 4)
		return (0);
	splitted = ft_split_str(filename, ".");
	if (!splitted)
		return (0);
	split_length = ft_arr_len_char(splitted);
	extension = splitted[split_length - 1];
	if (!str_are_equal(extension, "fdf"))
	{
		free_str_arr_null(splitted);
		return (0);
	}
	free_str_arr_null(splitted);
	return (1);
}

int	map_can_be_opened(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	map_is_ascii(char *filename)
{
	int		fd;
	int		bytes_read;
	char	buffer[4096];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, 4096);
	if (bytes_read < 1)
		return (0);
	while (bytes_read > 0)
	{
		if (!check_only_ascii(buffer, bytes_read))
			return (0);
		bytes_read = read(fd, buffer, 4096);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	check_only_ascii(char buffer[4096], int num_bytes)
{
	int	i;

	i = 0;
	while (i < num_bytes)
	{
		if (!ft_isascii(buffer[i]))
			return (0);
		i++;
	}
	return (1);
}
