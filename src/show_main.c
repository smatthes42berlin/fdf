/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 10:36:01 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	init_xserver_conn(t_mlx_data *con_data);
static int	create_window(t_mlx_data *con_data);
static int	create_image(t_mlx_data *con_data, t_img_data *img);

int	handle_keypress(int keysym, t_mlx_data *con_data)
{
	if (keysym == XK_ESCAPE)
	{
		free_normal_exit(*con_data, con_data->img_data);
		free_point_coll(con_data->all_points);
		exit(1);
	}
	return (1);
}

int	handle_win_x_btn(t_mlx_data *con_data)
{
	free_normal_exit(*con_data, con_data->img_data);
	free_point_coll(con_data->all_points);
	exit(1);
	return (1);
}

int	show_points_mlibx(t_point_coll *all_points)
{
	t_mlx_data	con_data;
	t_img_data	img;

	if (!init_xserver_conn(&con_data))
		return (mlx_error());
	mlx_get_screen_size(con_data.mlx_ptr, &(con_data.screen_width),
			&(con_data.screen_height));
	if (!create_window(&con_data))
		return (free_xserver_con(con_data));
	if (!create_image(&con_data, &img))
		return (free_window(con_data));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	all_points->height++;
	draw_image(all_points, &img, con_data);
	mlx_put_image_to_window(con_data.mlx_ptr, con_data.win_ptr, img.img, 0, 0);
	con_data.img_data = img;
	con_data.all_points = all_points;
	mlx_hook(con_data.win_ptr, 2, (1L << 0), handle_keypress, &con_data);
	mlx_hook(con_data.win_ptr, 17, (1L << 0), handle_win_x_btn, &con_data);
	mlx_loop(con_data.mlx_ptr);
	free_normal_exit(con_data, img);
	return (0);
}

static int	init_xserver_conn(t_mlx_data *con_data)
{
	con_data->mlx_ptr = mlx_init();
	if (!con_data->mlx_ptr)
		return (0);
	return (1);
}

static int	create_window(t_mlx_data *con_data)
{
	int	width;
	int	height;

	width = con_data->screen_width;
	height = con_data->screen_height;
	con_data->win_ptr = mlx_new_window(con_data->mlx_ptr,
										width,
										height,
										"fdf");
	if (!con_data->win_ptr)
		return (0);
	return (1);
}

static int	create_image(t_mlx_data *con_data, t_img_data *img)
{
	img->img = mlx_new_image(con_data->mlx_ptr, con_data->screen_width,
			con_data->screen_height);
	if (!img->img)
		return (0);
	return (1);
}

int	mlx_error(void)
{
	ft_printf("Error: something went wrong with the mini_libx - library.\n");
	return (0);
}