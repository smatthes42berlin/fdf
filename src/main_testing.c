/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:22:38 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/21 11:15:47 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// read map
// check map
// display map

int	handle_input(int keysym, t_mlx_data *data)
{
	ft_printf("keysim is $%d$\n", keysym);
	ft_printf("Hook\n");
	if (keysym == XK_ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	return (1);
}

typedef struct s_bresen_data
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	rise_fall;
	int	f;
	int	lead_end;
}		t_bresen_data;

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	decide_rise_fall(int *rise_fall, int coord_1, int coord_2)
{
	if (coord_1 <= coord_2)
		*rise_fall = 1;
	else
		*rise_fall = -1;
}

void	decide_direction_x(t_bresen_data *data, int x1, int y1, int x2, int y2)
{
	if (x1 <= x2)
	{
		data->x = x1 + 1;
		data->y = y1;
		data->lead_end = x2;
		decide_rise_fall(&(data->rise_fall), y1, y2);
	}
	else
	{
		data->x = x2 + 1;
		data->y = y2;
		data->lead_end = x1;
		decide_rise_fall(&(data->rise_fall), y2, y1);
	}
}

void	decide_direction_y(t_bresen_data *data, int x1, int y1, int x2, int y2)
{
	if (y1 <= y2)
	{
		data->y = y1 + 1;
		data->x = x1;
		data->lead_end = y2;
		decide_rise_fall(&(data->rise_fall), x1, x2);
	}
	else
	{
		data->y = y2 + 1;
		data->x = x2;
		data->lead_end = y1;
		decide_rise_fall(&(data->rise_fall), x2, x1);
	}
}

void	draw_bresenham_lead_x(t_img_data *img, t_bresen_data *data, int x1,
		int y1, int x2, int y2)
{
	if (data->dx < 2)
		return ;
	decide_direction_x(data, x1, y1, x2, y2);
	data->f = 2 * data->dy - data->dx;
	while (data->x < data->lead_end)
	{
		if (data->f < 0)
		{
			my_mlx_pixel_put(img, data->x, data->y, 0x00FF0000);
			data->f = data->f + 2 * data->dy;
		}
		else
		{
			data->y = data->y + data->rise_fall * 1;
			my_mlx_pixel_put(img, data->x, data->y, 0x00FF0000);
			data->f = data->f + 2 * data->dy - 2 * data->dx;
		}
		data->x++;
	}
}

void	draw_bresenham_lead_y(t_img_data *img, t_bresen_data *data, int x1,
		int y1, int x2, int y2)
{
	if (data->dy < 2)
		return ;
	decide_direction_y(data, x1, y1, x2, y2);
	data->f = 2 * data->dx - data->dy;
	while (data->y < data->lead_end)
	{
		if (data->f < 0)
		{
			my_mlx_pixel_put(img, data->x, data->y, 0x00FF0000);
			data->f = data->f + 2 * data->dx;
		}
		else
		{
			data->x = data->x + data->rise_fall * 1;
			my_mlx_pixel_put(img, data->x, data->y, 0x00FF0000);
			data->f = data->f + 2 * data->dx - 2 * data->dy;
		}
		data->y++;
	}
}

void	bresenham(t_img_data *img, int x1, int y1, int x2, int y2)
{
	t_bresen_data	data;

	my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	my_mlx_pixel_put(img, x2, y2, 0x00FF0000);
	data.dx = ft_abs(x2 - x1);
	data.dy = ft_abs(y2 - y1);
	if (data.dy <= data.dx)
		draw_bresenham_lead_x(img, &data, x1, y1, x2, y2);
	else
		draw_bresenham_lead_y(img, &data, x1, y1, x2, y2);
}

#define M_PI 3.14159265358979323846

int	main(void)
{
	t_mlx_data data;
	t_img_data img;
	int width = 3000;
	int height = 1800;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, width, height, "Hello world!");
	img.img = mlx_new_image(data.mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	bresenham(&img, 100, 100, 2800, 1600);
	bresenham(&img, 2800, 100, 100, 1600);
	bresenham(&img, 100, 100, 500, 1500);
	bresenham(&img, 500, 100, 500, 1500);
	// bresenham(&img, 2600, 1600, 200, 100);
	// bresenham(&img, 100, 100, 102, 100);

	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	ft_printf("bits per pixel %d \n", img.bits_per_pixel);
	ft_printf("line_length %d \n", img.line_length);
	ft_printf("endian %d \n", img.endian);

	// mlx_key_hook(data.win_ptr, handle_input, &data);

	mlx_loop(data.mlx_ptr);

	// sleep(2);

	mlx_destroy_image(data.mlx_ptr, img.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return (1);
}