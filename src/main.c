/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:22:38 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/13 14:28:55 by smatthes         ###   ########.fr       */
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
		mlx_destroy_image(data->mlx_ptr, data->img);
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

#define M_PI 3.14159265358979323846

int	main(void)
{
	t_mlx_data data;
	t_img_data img;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);

	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello world!");

	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}

	img.img = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);

	if (!img.img)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}

	data.img = img.img;

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	// my_mlx_pixel_put(&img, 200, 200, 0x00FF0000);

	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	// float i = 0;
	// int cent_x = 500;
	// int cent_y = 500;
	// int r = 250;

	// while (i < 2 * M_PI)
	// {
	// 	float x = r * cos(i) + cent_x;
	// 	float y = r * sin(i) + cent_y;
	// 	my_mlx_pixel_put(&img, x, y, 255);
	// 	i += M_PI / 90;
	// }

	int i = 0;
	int j = 0;
	int max = WIDTH * HEIGHT;
	// int int_max = INT_MAX;
	// int num_steps = (int_max << 8) >> 8 / max;

	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			int red = (max - i * j) * 100 / max * 255 / 100;
			int green = (i * j) * 100 / max * 255 / 100;
			int color = create_trgb(255, red, green, 0);
			my_mlx_pixel_put(&img, j, i, color);
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	ft_printf("bits per pixel %d \n", img.bits_per_pixel);
	ft_printf("line_length %d \n", img.line_length);
	ft_printf("endian %d \n", img.endian);

	mlx_key_hook(data.win_ptr, handle_input, &data);

	mlx_loop(data.mlx_ptr);

	// sleep(2);

	mlx_destroy_image(data.mlx_ptr, img.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);

	return (1);
}