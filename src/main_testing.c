/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:22:38 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/27 10:49:25 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

	

	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	mlx_string_put(data.mlx_ptr, data.win_ptr, 1500,
			900, 0x00FF0000, "test123");

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