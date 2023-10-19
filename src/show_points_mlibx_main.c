/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_points_mlibx_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 18:38:53 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// connect x server
// open window
// draw points and lines

static int	init_xserver_conn(t_mlx_data *con_data);
static int	create_window(t_mlx_data *con_data);
static int	create_image(t_mlx_data *con_data, t_img_data *img);

int	show_points_mlibx(t_point_coll *all_points)
{
	t_mlx_data	con_data;
	t_img_data	img;

	if (!init_xserver_conn(&con_data))
		return (mlx_error());
	if (!create_window(&con_data))
		return (free_xserver_con(con_data));
	if (!create_image(&con_data, &img))
		return (free_window(con_data));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	all_points->height++;
	draw_points(all_points, img);
	mlx_put_image_to_window(con_data.mlx_ptr, con_data.win_ptr, img.img, WIDTH
			/ 2, 0);
	free_xserver_image(con_data, img);
	return (1);
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
	con_data->win_ptr = mlx_new_window(con_data->mlx_ptr, WIDTH, HEIGHT,
			"Hello world!");
	if (!con_data->win_ptr)
		return (0);
	return (1);
}

static int	create_image(t_mlx_data *con_data, t_img_data *img)
{
	img->img = mlx_new_image(con_data->mlx_ptr, WIDTH, HEIGHT);
	if (!img->img)
		return (0);
	return (1);
}

int	mlx_error(void)
{
	ft_printf("Error: something went wrong with the mini_libx - library.\n");
	return (0);
}