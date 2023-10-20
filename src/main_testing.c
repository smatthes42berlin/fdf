/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:22:38 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/20 17:02:08 by smatthes         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham(t_img_data *img, int x1, int y1, int x2, int y2)
{
	int	x1;
	int	x2;
	int	x;
	int	y1;
	int	y2;
	int	y;
	int	dx;
	int	dy;
	int	f;

	x1 = 100;
	x2 = 263;
	y1 = 100;
	y2 = 364;
	dx = x2 - x1;
	dy = y2 - y1;
	f = 2 * dy - dx;
	x = x1+1;
	y = y1;
	my_mlx_pixel_put(img, x1, y1, 0x00FF0000);
	my_mlx_pixel_put(img, x2, y2, 0x00FF0000);
	while (x < x2)
	{
		if (f < 0)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			f = f + 2 * dy;
		}
		else
		{
			y++;
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			f = f + 2 * dy - 2 * dx;
		}
		x++;
	}
}

#define M_PI 3.14159265358979323846

int	main(void)
{
	t_mlx_data data;
	t_img_data img;
	int width = 400;
	int height = 400;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, width, height, "Hello world!");
	img.img = mlx_new_image(data.mlx_ptr, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	bresenham(&img);

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