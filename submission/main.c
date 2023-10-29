/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 08:35:50 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 09:35:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_point_coll	all_points;

	if (!check_input_main(argc, argv))
		return (1);
	if (!parse_map_main(&all_points, argv[1]))
		return (1);
	proj_points_iso(&all_points);
	get_points_range(&all_points);
	calc_points_color(&all_points);
	show_points_mlibx(&all_points);
	return (0);
}
