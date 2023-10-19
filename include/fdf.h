/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/19 18:39:44 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib_main.h"
# include "mlx.h"

# define WIDTH 1000
# define HEIGHT 1000
# define XK_ESCAPE 0xff1b
# define R_LOW 0
# define G_LOW 102
# define B_LOW 0
# define R_HIGH 102
# define G_HIGH 51
# define B_HIGH 0

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			endian;
	int			line_length;
}				t_img_data;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img_data	img_data;
}				t_mlx_data;

typedef struct s_range_int
{
	int			min;
	int			max;
	int			len;
}				t_range_int;

typedef struct s_point_3
{
	int			x;
	int			y;
	int			z;
	int			r;
	int			g;
	int			b;
	int			t;
	int			trgb;
}				t_point_3;

typedef struct s_point_coll
{
	t_point_3	*points;
	int			height;
	int			width;
	t_range_int	x_range;
	t_range_int	y_range;
	t_range_int	z_range;
	int			num;
}				t_point_coll;

/* input checking */

int				check_input_main(int argc, char *argv[]);
int				check_file_extension(char *filename);
int				map_can_be_opened(char *filename);
int				map_is_ascii(char *filename);
int				check_only_ascii(char buffer[4096], int num_bytes);

/* parse map */

int				parse_map_main(t_point_coll *all_points, char *filename);
int				check_map_dimensions(char *filename, t_file_info *file_info);
int				check_only_empty_rows_at_end(t_file_info *file_info);
int				error_map_dimensions(t_file_info file_info);
int				check_rectangular_map(t_file_info file_info);
void			free_point_coll(t_point_coll *point_coll);
int				get_points(char *filename, t_file_info file_info,
					t_point_coll *all_points);
int				parse_file(int fd, t_point_coll *all_points);
int				parse_line_points(t_point_coll *all_points, char *row,
					int *pt_index, int row_index);
int				error_point_parsing(t_file_info file_info);

/* colors */

void			calc_points_color(t_point_coll *all_points);
int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

/* utils */

void			print_points(t_point_coll *points);
char			*gnl_no_newline(int fd);
void			print_point_info(t_point_coll *points);
void			get_points_range(t_point_coll *all_points);

/* project points iso */

void			proj_points_iso(t_point_coll *all_points);

/* show points mlibx */

int				show_points_mlibx(t_point_coll *all_points);
int				free_xserver_con(t_mlx_data con_data);
int				free_xserver_con_err(t_mlx_data con_data);
int				free_window(t_mlx_data con_data);
int				free_xserver_image(t_mlx_data con_data, t_img_data img);
int				mlx_error(void);

#endif