/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_points_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:32:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 10:24:43 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// cos(30degree) = 0.866025
// sin(30degree) = 0.5
void	proj_points_iso(t_point_coll *all_points)
{
	int			i;
	t_point_3	*cur_pt;
	float		res_float;

	i = 0;
	while (i < all_points->num)
	{
		cur_pt = &(all_points->points[i]);
		res_float = (cur_pt->x - cur_pt->y) * 0.866025 * PT_ISO_ACCURACY;
		cur_pt->x_iso_acc = res_float;
		res_float = ((cur_pt->x + cur_pt->y) * 0.5 - cur_pt->z)
			* PT_ISO_ACCURACY;
		cur_pt->y_iso_acc = res_float;
		i++;
	}
}
