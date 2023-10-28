/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:38:48 by smatthes          #+#    #+#             */
/*   Updated: 2023/10/28 09:37:21 by smatthes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib_main.h"
# include "mlx.h"

# define WIDTH 3500
# define HEIGHT 2000
# define XK_ESCAPE 0xff1b
# define R_LOW 255
# define G_LOW 0
# define B_LOW 0
# define R_HIGH 255
# define G_HIGH 255
# define B_HIGH 255
# define PT_ISO_ACCURACY 10000.0

typedef struct s_range_int
{
	int				min;
	int				max;
	int				len;
}					t_range_int;

typedef struct s_point_3
{
	int				x;
	int				y;
	int				z;
	long			x_iso_acc;
	long			y_iso_acc;
	int				r;
	int				g;
	int				b;
	int				t;
	int				trgb;
	int				img_x;
	int				img_y;
}					t_point_3;

typedef struct s_point_coll
{
	t_point_3		*points;
	int				height;
	int				width;
	t_range_int		x_range_iso_acc;
	t_range_int		y_range_iso_acc;
	t_range_int		z_range;
	int				num;
}					t_point_coll;

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				endian;
	int				line_length;
	int				margin;
	float			scale_y;
	float			scale_x;
	float			scale;
	int				offset_x;
	int				offset_y;
}					t_img_data;

typedef struct s_mlx_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				screen_width;
	int				screen_height;
	t_img_data		img_data;
	t_point_coll	*all_points;
}					t_mlx_data;

typedef struct s_bresen_data
{
	int				x;
	int				y;
	int				dx;
	int				dy;
	int				rise_fall;
	int				f;
	int				lead_end;
	t_point_3		*pt_start;
	t_point_3		*pt_end;
}					t_bresen_data;

/* input checking */

int					check_input_main(int argc, char *argv[]);
int					check_file_extension(char *filename);
int					map_can_be_opened(char *filename);
int					map_is_ascii(char *filename);
int					check_only_ascii(char buffer[4096], int num_bytes);

/* parse map */

int					parse_map_main(t_point_coll *all_points, char *filename);
int	check_map_dimensions(char *filename,
							t_file_info *file_info);
int					check_only_empty_rows_at_end(t_file_info *file_info);
int					error_map_dimensions(t_file_info file_info);
int					check_rectangular_map(t_file_info file_info);
int					check_more_than_one_point(t_file_info *file_info);
void				free_point_coll(t_point_coll *point_coll);
int					get_points(char *filename, t_file_info file_info,
						t_point_coll *all_points);
int					parse_file(int fd, t_point_coll *all_points);
int					parse_line_points(t_point_coll *all_points, char *row,
						int *pt_index, int row_index);
int					error_point_parsing(t_file_info file_info);

/* colors */

void				calc_points_color(t_point_coll *all_points);
int					create_trgb(int t, int r, int g, int b);
int					get_t(int trgb);
int					get_r(int trgb);
int					get_g(int trgb);
int					get_b(int trgb);

/* utils */

void				print_points(t_point_coll *points);
char				*gnl_no_newline(int fd);
void				print_point_info(t_point_coll *points);
void				get_points_range(t_point_coll *all_points);
void				print_point(t_point_3 point);

/* project points iso */

void				proj_points_iso(t_point_coll *all_points);

/* show points mlibx */

int					show_points_mlibx(t_point_coll *all_points);
int					free_xserver_con(t_mlx_data con_data);
int					free_window(t_mlx_data con_data);
int					free_xserver_image(t_mlx_data con_data, t_img_data img);
void				free_normal_exit(t_mlx_data con_data, t_img_data img);
int					mlx_error(void);
void				draw_image(t_point_coll *all_points, t_img_data *img,
						t_mlx_data con_data);
void	calc_points_img_coords(t_point_coll *all_points,
							t_img_data *img,
							t_mlx_data con_data);
void				calc_ppu(t_point_coll *all_points, t_mlx_data con_data,
						t_img_data *img);
void				my_mlx_pixel_put(t_img_data *data, int x, int y, int color);

/* draw line bresenham */

void				draw_lin_bresenham(t_img_data *img, t_point_3 p1,
						t_point_3 p2);
void				draw_bresenham_lead_x(t_img_data *img, t_bresen_data *data,
						t_point_3 p1, t_point_3 p2);
void				draw_bresenham_lead_y(t_img_data *img, t_bresen_data *data,
						t_point_3 p1, t_point_3 p2);
void				decide_rise_fall(int *rise_fall, int coord_1, int coord_2);
void				decide_direction_x(t_bresen_data *data, t_point_3 *p1,
						t_point_3 *p2);
void				decide_direction_y(t_bresen_data *data, t_point_3 *p1,
						t_point_3 *p2);
int					interpolate_col_x(t_bresen_data data, int cur_x);
int					interpolate_col_y(t_bresen_data data, int cur_y);

/* draw lines */

void				draw_lines(t_point_coll *all_points, t_img_data *img);

#endif