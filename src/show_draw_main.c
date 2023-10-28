/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_draw_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/27 14:52:54 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	draw_image(t_point_coll *all_points, t_img_data *img,
		t_mlx_data con_data)
{
	calc_points_img_coords(all_points, img, con_data);
	draw_lines(all_points, img);
}

