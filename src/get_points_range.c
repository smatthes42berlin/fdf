/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_points_range.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:08:17 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/27 14:40:31 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_range(t_range_int *range, int val);
static void	calc_range_len(t_range_int *range);
static void	adjust_range(t_range_int *range, int val);

void	get_points_range(t_point_coll *all_points)
{
	int			i;
	t_point_3	cur_pt;

	i = 0;
	while (i < all_points->num)
	{
		cur_pt = all_points->points[i];
		if (i != 0)
		{
			adjust_range(&(all_points->x_range_iso_acc), cur_pt.x_iso_acc);
			adjust_range(&(all_points->y_range_iso_acc), cur_pt.y_iso_acc);
			adjust_range(&(all_points->z_range), cur_pt.z);
		}
		else
		{
			set_range(&(all_points->x_range_iso_acc), cur_pt.x_iso_acc);
			set_range(&(all_points->y_range_iso_acc), cur_pt.y_iso_acc);
			set_range(&(all_points->z_range), cur_pt.z);
		}
		i++;
	}
	calc_range_len(&(all_points->x_range_iso_acc));
	calc_range_len(&(all_points->y_range_iso_acc));
	calc_range_len(&(all_points->z_range));
}

static void	set_range(t_range_int *range, int val)
{
	range->min = val;
	range->max = val;
}

static void	calc_range_len(t_range_int *range)
{
	range->len = range->max - range->min;
}

static void	adjust_range(t_range_int *range, int val)
{
	if (val < range->min)
		range->min = val;
	if (val > range->max)
		range->max = val;
}
