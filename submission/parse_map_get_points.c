/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_get_points.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:28:19 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 08:58:39 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	error(t_point_coll *all_points);

int	get_points(char *filename, t_file_info file_info, t_point_coll *all_points)
{
	int	fd;

	all_points->height = file_info.rows;
	all_points->width = file_info.cols[0];
	all_points->num = file_info.rows * file_info.cols[0];
	all_points->points = malloc((all_points->num)
			* sizeof(*(all_points->points)));
	if (!all_points->points)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (error(all_points));
	if (!parse_file(fd, all_points))
	{
		close(fd);
		return (error(all_points));
	}
	if (close(fd) == -1)
		return (error(all_points));
	return (1);
}

int	parse_file(int fd, t_point_coll *all_points)
{
	char	*next_line;
	int		pt_index;
	int		row_index;

	pt_index = 0;
	row_index = 0;
	next_line = gnl_no_newline(fd);
	if (!next_line)
		return (0);
	while (next_line)
	{
		if (!next_line && pt_index < all_points->num)
			return (0);
		if (str_is_empty(next_line))
			break ;
		if (next_line && !str_is_empty(next_line))
		{
			if (!parse_line_points(all_points, next_line, &pt_index, row_index))
				return (0);
			row_index++;
		}
		free(next_line);
		next_line = gnl_no_newline(fd);
	}
	return (1);
}

int	parse_line_points(t_point_coll *all_points, char *row, int *pt_index,
		int row_index)
{
	char	**pts_str;
	int		i;

	pts_str = ft_split(row, ' ');
	i = 0;
	if (!pts_str)
		return (0);
	while (pts_str[i])
	{
		all_points->points[*pt_index].y = row_index;
		all_points->points[*pt_index].x = i;
		all_points->points[*pt_index].z = ft_atoi_secure(pts_str[i]);
		(*pt_index)++;
		i++;
	}
	free_str_arr_null(pts_str);
	return (1);
}

static int	error(t_point_coll *all_points)
{
	free_point_coll(all_points);
	return (0);
}
