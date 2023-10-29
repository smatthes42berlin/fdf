/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:01:54 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/29 13:03:56 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
