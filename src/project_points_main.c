/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_points_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:32:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 17:39:17 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// cos(30degree) = 0.866025
// sin(30degree) = 0.5
void	proj_points_iso(t_point_coll *all_points)
{
	int			x_org;
	int			y_org;
	int			i;
	t_point_3	*cur_pt;

	i = 0;
	while (i < all_points->num)
	{
		cur_pt = &(all_points->points[i]);
		x_org = cur_pt->x;
		y_org = cur_pt->y;
		cur_pt->x = (x_org - y_org) * 0.866025;
		cur_pt->y = (x_org + y_org) * 0.5 - cur_pt->z;
		i++;
	}
}
