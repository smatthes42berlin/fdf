/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_points_mlibx_draw.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/20 15:32:37 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_ppu(t_point_coll *all_points, t_mlx_data con_data,
				t_img_data *img);

void	draw_points(t_point_coll *all_points, t_img_data *img,
		t_mlx_data con_data)
{
	int			i;
	int			x_draw;
	int			y_draw;
	t_point_3	*cur_pt;
	int			color;

	i = 0;
	img->margin = 100;
	color = create_trgb(255, 255, 0, 0);
	calc_ppu(all_points, con_data, img);
	my_mlx_pixel_put(img, WIDTH / 2, HEIGHT / 2, color);
	while (i < all_points->num)
	{
		cur_pt = &(all_points->points[i]);
		x_draw = (float)(cur_pt->x - all_points->x_range.min) * img->scale
			+ img->margin + img->offset_x;
		y_draw = (float)(cur_pt->y - all_points->y_range.min) * img->scale
			+ img->margin + img->offset_y;
		// ft_printf("x_draw is $%d$\n", x_draw);
		// ft_printf("y_draw is $%d$\n", y_draw);
		// ft_printf("r is $%d$\n", get_r(cur_pt->trgb));
		// ft_printf("g is $%d$\n", get_g(cur_pt->trgb));
		// ft_printf("b is $%d$\n", get_b(cur_pt->trgb));
		// ft_printf("\n\n");
		my_mlx_pixel_put(img, x_draw, y_draw, cur_pt->trgb);
		i++;
	}
}

#include <stdio.h>

static void	calc_ppu(t_point_coll *all_points, t_mlx_data con_data,
		t_img_data *img)
{
	float	draw_screen_width;
	float	draw_screen_height;

	draw_screen_width = con_data.screen_width - img->margin - 200;
	draw_screen_height = con_data.screen_height - img->margin - 200;
	printf("draw screen width = $%f$\n", draw_screen_width);
	printf("draw screen height = $%f$\n", draw_screen_height);
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
	// img->offset_x = 200;
	// img->offset_y = 0;
	// img->scale_x = 1;
	// img->scale_y = 1;
	printf("screen_x = $%d$\n", con_data.screen_width);
	printf("screen_y = $%d$\n", con_data.screen_height);
	printf("margin = $%d$\n", img->margin);
	printf("offset_x = $%d$\n", img->offset_x);
	printf("offset_y = $%d$\n", img->offset_y);
	printf("scale_x = $%f$\n", img->scale_x);
	printf("scale_y = $%f$\n", img->scale_y);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
