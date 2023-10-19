/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_points_mlibx_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 18:41:52 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_xserver_con_err(t_mlx_data con_data)
{
	mlx_destroy_display(con_data.mlx_ptr);
	free(con_data.mlx_ptr);
	return (mlx_error());
}

int	free_window(t_mlx_data con_data)
{
	mlx_destroy_window(con_data.mlx_ptr, con_data.win_ptr);
	return (free_xserver_con(con_data));
}

int	free_xserver_image(t_mlx_data con_data, t_img_data img)
{
	mlx_destroy_image(con_data.mlx_ptr, img.img);
	return (free_window(con_data));
}
