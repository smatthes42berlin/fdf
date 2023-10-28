/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:07:24 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/27 14:40:34 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_points(t_point_coll *points)
{
	int	i;

	i = 0;
	while (i < points->num)
	{
		print_point(points->points[i]);
		i++;
	}
}

void	print_point(t_point_3 point)
{
	ft_printf("xyz_org = %d ; %d ; %d | ", point.x, point.y, point.z);
	ft_printf("xyz_iso = %d ; %d ; %d | ", point.x_iso_acc, point.y_iso_acc,
			point.z);
	ft_printf("%d ; %d ; %d\n", point.r, point.g, point.b);
}
void	print_point_info(t_point_coll *points)
{
	ft_printf("num = $%d$\n", points->num);
	ft_printf("height = $%d$\n", points->height);
	ft_printf("width = $%d$\n", points->width);
	ft_printf("x_max = $%d$\n", points->x_range_iso_acc.max);
	ft_printf("x_min = $%d$\n", points->x_range_iso_acc.min);
	ft_printf("x_range_iso_acc = $%d$\n", points->x_range_iso_acc.len);
	ft_printf("y_max = $%d$\n", points->y_range_iso_acc.max);
	ft_printf("y_min = $%d$\n", points->y_range_iso_acc.min);
	ft_printf("y_range_iso_acc = $%d$\n", points->y_range_iso_acc.len);
	ft_printf("z_max = $%d$\n", points->z_range.max);
	ft_printf("z_min = $%d$\n", points->z_range.min);
	ft_printf("z_range = $%d$\n", points->z_range.len);
}
