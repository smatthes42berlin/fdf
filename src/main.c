/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:35:50 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/15 19:15:35 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// read map into points
// transform points isometric
// calculate necessary window dimensions
// calculate color
// plot points and draw lines

#include "fdf.h"

int	main(int argc, char *argv[])
{
	// t_point_coll all_points;
	t_file_info file_info;

	file_info.sep = ' ';
	if (!check_input_main(argc, argv))
		return (1);
	// problem, when no newline, there is still one line in file
	// have to check
	int res = count_cols_per_line_filename(argv[1], &file_info);
	ft_printf("res = $%d$\n", res);
	ft_printf("line_length = $%d$\n", file_info.rows);
	print_int_arr(file_info.cols, file_info.rows);
	// if (!parse_map(&all_points, argv[1]))
	// 	return (1);
	return (0);
}