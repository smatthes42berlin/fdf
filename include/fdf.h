/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/15 14:40:26 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib_main.h"
# include "mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define XK_ESCAPE 0xff1b

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img_data;
}				t_mlx_data;

typedef struct s_point_3
{
	int			x;
	int			y;
	int			z;
}				t_point_3;

typedef struct s_point_coll
{
	t_point_3	*points;
	int			num;
}				t_point_coll;

/* input checking */

int				check_input_main(int argc, char *argv[]);
int				check_file_extension(char *filename);
int				map_can_be_opened(char *filename);
int				map_is_ascii(char *filename);
int				check_only_ascii(char buffer[4096], int num_bytes);
char			*gnl_no_newline(int fd);

/* parse map */

int				parse_map(t_point_coll *all_points, char *filename);
int				check_map_dimensions(char *filename, int *map_width,
					int *map_height);
int				check_row_per_row(int fd, int *map_width, int *map_height);
int				check_row_against_prev(int row_length, int map_width);
int				error_map_dimensions(void);

/* colors */

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

#endif