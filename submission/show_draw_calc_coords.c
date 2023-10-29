/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_draw_calc_coords.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/27 16:52:15 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calc_points_img_coords(t_point_coll *all_points, t_img_data *img,
		t_mlx_data con_data)
{
	int			i;
	t_point_3	*cur_pt;

	i = 0;
	img->margin = 100;
	calc_ppu(all_points, con_data, img);
	while (i < all_points->num)
	{
		cur_pt = &(all_points->points[i]);
		cur_pt->img_x = (float)(cur_pt->x_iso_acc
				- all_points->x_range_iso_acc.min) / PT_ISO_ACCURACY
			* img->scale + img->margin + img->offset_x;
		cur_pt->img_y = (float)(cur_pt->y_iso_acc
				- all_points->y_range_iso_acc.min) / PT_ISO_ACCURACY
			* img->scale + img->margin + img->offset_y;
		cur_pt->x = cur_pt->img_x;
		cur_pt->y = cur_pt->img_y;
		i++;
	}
}

void	calc_ppu(t_point_coll *all_points, t_mlx_data con_data, t_img_data *img)
{
	float	draw_screen_width;
	float	draw_screen_height;

	draw_screen_width = con_data.screen_width - img->margin - 200;
	draw_screen_height = con_data.screen_height - img->margin - 200;
	img->offset_x = 0;
	img->offset_y = 0;
	img->scale_x = (float)(con_data.screen_width - img->margin - 200)
		/ (float)(all_points->x_range_iso_acc.len / PT_ISO_ACCURACY);
	img->scale_y = (float)(con_data.screen_height - img->margin - 200)
		/ (float)(all_points->y_range_iso_acc.len / PT_ISO_ACCURACY);
	if (img->scale_x < img->scale_y)
	{
		img->offset_y = (1 - (img->scale_x / img->scale_y)) * draw_screen_height
			/ 2;
		img->scale = img->scale_x;
	}
	else
	{
		img->offset_x = (1 - (img->scale_y / img->scale_x)) * draw_screen_width
			/ 2;
		img->scale = img->scale_y;
	}
}
