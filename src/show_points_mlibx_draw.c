/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_points_mlibx_draw.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/21 11:40:40 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	draw_image(t_point_coll *all_points, t_img_data *img,
		t_mlx_data con_data)
{
	calc_points_img_coords(all_points, img, con_data);
	draw_lines(all_points, img, con_data);
}

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
		cur_pt->img_x = (float)(cur_pt->x - all_points->x_range.min)
			* img->scale + img->margin + img->offset_x;
		cur_pt->img_y = (float)(cur_pt->y - all_points->y_range.min)
			* img->scale + img->margin + img->offset_y;
		my_mlx_pixel_put(img, cur_pt->img_x, cur_pt->img_y, cur_pt->trgb);
		i++;
	}
}

void	calc_ppu(t_point_coll *all_points, t_mlx_data con_data,
		t_img_data *img)
{
	float	draw_screen_width;
	float	draw_screen_height;

	draw_screen_width = con_data.screen_width - img->margin - 200;
	draw_screen_height = con_data.screen_height - img->margin - 200;
	img->offset_x = 0;
	img->offset_y = 0;
	img->scale_x = (float)(con_data.screen_width - img->margin - 200)
		/ (float)all_points->x_range.len;
	img->scale_y = (float)(con_data.screen_height - img->margin - 200)
		/ (float)all_points->y_range.len;
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

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
