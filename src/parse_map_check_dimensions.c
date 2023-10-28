/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_check_dimensions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:28:19 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 09:05:08 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_map_dimensions(char *filename, t_file_info *file_info)
{
	int	res;

	file_info->sep = ' ';
	res = count_cols_per_line_filename(filename, file_info);
	if (res == -1)
		return (0);
	if (!check_only_empty_rows_at_end(file_info))
		return (0);
	if (!check_more_than_one_point(file_info))
		return (0);
	if (!check_rectangular_map(*file_info))
		return (0);
	return (1);
}

int	check_only_empty_rows_at_end(t_file_info *file_info)
{
	int	i;
	int	empty_row_state;
	int	non_empty_rows;

	i = 0;
	empty_row_state = 0;
	non_empty_rows = file_info->rows;
	while (i < file_info->rows)
	{
		if (file_info->cols[i] == 0 && empty_row_state == 0)
		{
			non_empty_rows = i;
			empty_row_state = 1;
		}
		if (file_info->cols[i] != 0 && empty_row_state == 1)
			return (0);
		i++;
	}
	file_info->rows = non_empty_rows;
	return (1);
}

int	check_rectangular_map(t_file_info file_info)
{
	int	i;
	int	rec_width;

	rec_width = file_info.cols[0];
	i = 1;
	while (i < file_info.rows)
	{
		if (file_info.cols[i] != 0 && file_info.cols[i] != rec_width)
			return (0);
		i++;
	}
	return (1);
}

int	check_more_than_one_point(t_file_info *file_info)
{
	if (file_info->cols[0] == 1 && file_info->rows == 1)
		return (0);
	return (1);
}
