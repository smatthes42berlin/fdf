/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:22:38 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/06 11:09:50 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// read map
// check map
// display map

int	main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	if (NULL == mlx)
		return (1);

    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
    sleep(2);
    // mlx_loop(mlx);

    mlx_destroy_window(mlx, mlx_win);
    mlx_destroy_display(mlx);
    free(mlx);

	return (1);
}