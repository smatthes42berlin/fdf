/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_points_color_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:23:29 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 18:00:14 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	set_rgb(t_point_3 *point, int r, int g, int b);
static void	interpolate_rgb(float pos, t_point_3 *point);

void	calc_points_color(t_point_coll *all_points)
{
	float		pos;
	int			i;
	t_point_3	*cur_pt;

	i = 0;
	while (i < all_points->num)
	{
		cur_pt = &(all_points->points[i]);
		if (all_points->z_range.len == 0)
			set_rgb(cur_pt, R_LOW, G_LOW, B_LOW);
		else
		{
			pos = ((float)(cur_pt->z - all_points->z_range.min))
				/ (float)all_points->z_range.len;
			interpolate_rgb(pos, cur_pt);
		}
		cur_pt->trgb = create_trgb(1, cur_pt->r, cur_pt->g, cur_pt->b);
		i++;
	}
}

static void	set_rgb(t_point_3 *point, int r, int g, int b)
{
	point->r = r;
	point->g = g;
	point->b = b;
}

static void	interpolate_rgb(float pos, t_point_3 *point)
{
	int	r;
	int	g;
	int	b;

	r = ft_abs((R_LOW - R_HIGH) * pos);
	g = ft_abs((G_LOW - G_HIGH) * pos);
	b = ft_abs((B_LOW - B_HIGH) * pos);
	set_rgb(point, r, g, b);
}
