/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:07:24 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 17:13:27 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_point_coll *points)
{
	int	i;

	i = 0;
	while (i < points->num)
	{
		ft_printf("%d ; %d ; %d | ", points->points[i].x, points->points[i].y,
				points->points[i].z);
		ft_printf("%d ; %d ; %d\n", points->points[i].r, points->points[i].g,
				points->points[i].b);
		i++;
	}
}

void	print_point_info(t_point_coll *points)
{
	ft_printf("num = $%d$\n", points->num);
	ft_printf("height = $%d$\n", points->height);
	ft_printf("width = $%d$\n", points->width);
	ft_printf("x_max = $%d$\n", points->x_range.max);
	ft_printf("x_min = $%d$\n", points->x_range.min);
	ft_printf("x_range = $%d$\n", points->x_range.len);
	ft_printf("y_max = $%d$\n", points->y_range.max);
	ft_printf("y_min = $%d$\n", points->y_range.min);
	ft_printf("y_range = $%d$\n", points->y_range.len);
	ft_printf("z_max = $%d$\n", points->z_range.max);
	ft_printf("z_min = $%d$\n", points->z_range.min);
	ft_printf("z_range = $%d$\n", points->z_range.len);
}
