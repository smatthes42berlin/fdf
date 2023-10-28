/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_draw_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 09:02:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lines(t_point_coll *all_points, t_img_data *img)
{
	int			i;
	t_point_3	cur_pt;
	t_point_3	prev_pt;
	int			col_num;

	col_num = all_points->width;
	i = 1;
	while (i < all_points->num)
	{
		cur_pt = all_points->points[i];
		prev_pt = all_points->points[i - 1];
		if (i % col_num != 0)
			draw_lin_bresenham(img, cur_pt, prev_pt);
		if (i / col_num != 0)
		{
			prev_pt = all_points->points[i - col_num];
			draw_lin_bresenham(img, cur_pt, prev_pt);
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
