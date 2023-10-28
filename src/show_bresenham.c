/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_bresenham.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:16:37 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/27 16:00:11 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_lin_bresenham(t_img_data *img, t_point_3 p1, t_point_3 p2)
{
	t_bresen_data	data;

	my_mlx_pixel_put(img, p1.x, p1.y, p1.trgb);
	my_mlx_pixel_put(img, p2.x, p2.y, p2.trgb);
	data.dx = ft_abs(p2.x - p1.x);
	data.dy = ft_abs(p2.y - p1.y);
	if (data.dy <= data.dx)
		draw_bresenham_lead_x(img, &data, p1, p2);
	else
		draw_bresenham_lead_y(img, &data, p1, p2);
}
void	draw_bresenham_lead_x(t_img_data *img, t_bresen_data *data,
		t_point_3 p1, t_point_3 p2)
{
	int	color;

	if (data->dx < 2)
		return ;
	decide_direction_x(data, &p1, &p2);
	data->f = 2 * data->dy - data->dx;
	while (data->x < data->lead_end)
	{
		color = interpolate_col_x(*data, data->x);
		if (data->f < 0)
		{
			my_mlx_pixel_put(img, data->x, data->y, color);
			data->f = data->f + 2 * data->dy;
		}
		else
		{
			data->y = data->y + data->rise_fall * 1;
			my_mlx_pixel_put(img, data->x, data->y, color);
			data->f = data->f + 2 * data->dy - 2 * data->dx;
		}
		data->x++;
	}
}

void	draw_bresenham_lead_y(t_img_data *img, t_bresen_data *data,
		t_point_3 p1, t_point_3 p2)
{
	int	color;

	if (data->dy < 2)
		return ;
	decide_direction_y(data, &p1, &p2);
	data->f = 2 * data->dx - data->dy;
	while (data->y < data->lead_end)
	{
		color = interpolate_col_y(*data, data->y);
		if (data->f < 0)
		{
			my_mlx_pixel_put(img, data->x, data->y, color);
			data->f = data->f + 2 * data->dx;
		}
		else
		{
			data->x = data->x + data->rise_fall * 1;
			my_mlx_pixel_put(img, data->x, data->y, color);
			data->f = data->f + 2 * data->dx - 2 * data->dy;
		}
		data->y++;
	}
}
