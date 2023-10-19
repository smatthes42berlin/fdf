/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:28:19 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 17:26:42 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse_map_main(t_point_coll *all_points, char *filename)
{
	t_file_info	file_info;

	all_points->points++;
	file_info.rows = 0;
	file_info.cols = NULL;
	if (!check_map_dimensions(filename, &file_info))
		return (error_map_dimensions(file_info));
	if (!get_points(filename, file_info, all_points))
		return (error_point_parsing(file_info));
	free_file_info(file_info);
	return (1);
}

int	error_map_dimensions(t_file_info file_info)
{
	free_file_info(file_info);
	ft_printf("Error: something went wrong when checking map dimensions.");
	ft_printf(" Make sure map is rectangular");
	ft_printf(" and and only contains newlines at the end!\n");
	return (0);
}

int	error_point_parsing(t_file_info file_info)
{
	free_file_info(file_info);
	ft_printf("Error: something went wrong while parsing the maps points.\n");
	return (0);
}

// int	parse_lines(t_point_coll *all_points, int fd)
// {
// }
