/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:28:19 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/15 11:09:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_map(t_point_coll *all_points, char *filename)
{
	int	fd;
	int	map_width;
	int	map_height;

	all_points->points++;
	if (!check_map_dimensions(filename, &map_width, &map_height))
		return (error_map_dimensions());
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error_map_dimensions());
	// if (!parse_lines(all_points, fd))
	// 	return (error_map_dimensions());
	if (close(fd) == -1)
		return (error_map_dimensions());
	return (1);
}

int	error_map_dimensions(void)
{
	ft_printf("Error: something went wrong when checking map dimensions.");
	ft_printf(" Make sure map is rectangular!");
	return (0);
}

// int	parse_lines(t_point_coll *all_points, int fd)
// {
// }
