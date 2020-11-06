/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarkita <tmarkita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:59:59 by k3                #+#    #+#             */
/*   Updated: 2020/11/06 17:57:38 by k3               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

# define W_WIDTH	1024
# define W_HEIGHT	600
# define WHITE		0xFFFFFFu
# define KEY_ESC	53
# define KEY_D		2
# define KEY_C		8
# define KEY_Q		12
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_Z		6
# define KEY_X		7
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_I		34
# define KEY_O		31

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	unsigned	color;
}				t_point;

typedef struct	s_render
{
	int			scale;
	int			pos_x;
	int			pos_y;
	float		ang_x;
	float		ang_y;
	float		ang_z;
	int			iso;
	t_point		**points;
}				t_render;

typedef struct	s_image
{
	void		*img_ptr;
	char		*img_str;
	int			bpp;
	int			size;
	int			endian;
}				t_image;

typedef struct	s_coord
{
	int			z;
}				t_coord;

typedef struct	s_map
{
	int			width;
	int			height;
	t_coord		**coords;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_image		*frame;
	t_render	*render;
}				t_fdf;

void			put_error(char *msg);
t_map			*read_map(int fd);
t_fdf			*init_mlx(void);
void			put_pixel(t_fdf *fdf, int x, int y, unsigned color);
void			draw_map(t_fdf *fdf);
int				press_key(int key, t_fdf *fdf);
t_image			*new_frame(t_fdf *fdf);
void			clear_frame(t_fdf *fdf);
void			map_to_points(t_fdf *fdf);
int				str_to_coord(t_map *map, char *line);
int				dist(int a, int b);
int				smart_atoi(char *str);
void			rotate_x(t_point *p, double ang);
void			rotate_y(t_point *p, double ang);
void			rotate_z(t_point *p, double ang);
void			map_x(t_fdf *fdf, int key);
void			map_y(t_fdf *fdf, int key);
void			map_z(t_fdf *fdf, int key);
void			map_projection(t_fdf *fdf, int key);
void			map_zoom(t_fdf *fdf, int key);
void			map_move(t_fdf *fdf, int key);
void			update_img(t_fdf *fdf);
void			iso(t_point *p);

#endif
