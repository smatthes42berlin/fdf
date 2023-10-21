/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_points_mlibx_bresenham_utils.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:16:37 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/21 11:23:09 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	decide_rise_fall(int *rise_fall, int coord_1, int coord_2)
{
	if (coord_1 <= coord_2)
		*rise_fall = 1;
	else
		*rise_fall = -1;
}

void	decide_direction_x(t_bresen_data *data, t_point_3 p1, t_point_3 p2)
{
	if (p1.x <= p2.x)
	{
		data->x = p1.x + 1;
		data->y = p1.y;
		data->lead_end = p2.x;
		decide_rise_fall(&(data->rise_fall), p1.y, p2.y);
	}
	else
	{
		data->x = p2.x + 1;
		data->y = p2.y;
		data->lead_end = p1.x;
		decide_rise_fall(&(data->rise_fall), p2.y, p1.y);
	}
}

void	decide_direction_y(t_bresen_data *data, t_point_3 p1, t_point_3 p2)
{
	if (p1.y <= p2.y)
	{
		data->y = p1.y + 1;
		data->x = p1.x;
		data->lead_end = p2.y;
		decide_rise_fall(&(data->rise_fall), p1.x, p2.x);
	}
	else
	{
		data->y = p2.y + 1;
		data->x = p2.x;
		data->lead_end = p1.y;
		decide_rise_fall(&(data->rise_fall), p2.x, p1.x);
	}
}
