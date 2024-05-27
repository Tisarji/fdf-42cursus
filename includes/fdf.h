/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:35:33 by jikarunw          #+#    #+#             */
/*   Updated: 2024/05/27 16:01:09 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

# include <fcntl.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720

# define DEFALUT_COLOR 0xFFFFFFFF
# define COOL_COLOR 0x0000FF
# define WARM_COLOR 0xFF0000

typedef struct s_coords
{
	float	x;
	float	y;
	float	z;
}				t_coords;

typedef struct	s_map
{
	int				width;
	int				height;
	float			scale;
	t_coords		*s_coord;
	struct s_map	*next;
}					t_map;

typedef struct	s_matrix_width
{
	float			width;
	float			min_width;
	float			max_width;
}					t_matrix_width;

typedef struct	s_matrix_height
{
	float			height;
	float			min_height;
	float			max_height;
}					t_matrix_height;

typedef struct	s_matrix_dimens
{
	float			matrix_height;
	float			matrix_width;
}					t_matrix_dimens;

typedef struct	s_draw_line
{
	int				dx;
	int				dy;
	int				control;
	int				offset_x;
	int				offset_y;
	mlx_image_t		*img;
}					t_draw_line;

typedef struct s_color
{
	uint8_t		r1;
	uint8_t		r2;
	uint8_t		g1;
	uint8_t		g2;
	uint8_t		b1;
	uint8_t		b2;
	uint8_t		a;
	uint32_t	color;
}	t_color;

/***********************
 *   SECTION - FREE    *
 * PATH DIR: SRCS/MISC *
 ***********************/

/* utils.c */
t_draw_line		*new_line(mlx_image_t *img, float **mconvert_matrix, int start, int end);
void			draw_background(mlx_image_t *img);
void			put_pixel(mlx_image_t *img, int x, int y, int color);

/* parser.c */
int				ft_parser_map(const char *argv);

/* ft_free.c */
void			free_data(t_map *data);
void			free_split(char **split);
void			free_matrix(float **map);

/* color.c */
int				gradient_color(int y1, int y2, int step, int steps);

/****************************
 *   SECTION - ALGORITHM    *
 * PATH DIR: SRCS/ALGORITHM *
 ****************************/

/* render.c */
void			render(t_map *map, mlx_image_t *img);
float			**get_map_matrix(t_map *map);
float			**convert_matrix(t_map *map, float **map_matrix);
void			draw_map(t_map *map, mlx_image_t *img, float **convert_matrix);

/* map_read.c */
t_map			*map_read(const char *argv);
t_map			*new_list(char *line, int y);
t_map			*insert_node(t_map *head, t_map *list);
t_map			*new_node(int x, int y, int z);

/* get_dims.c */
t_matrix_width	*get_matrix_width(float **map_matrix, t_map *map);
t_matrix_height	*get_matrix_height(float **map_matrix, t_map *map);
t_matrix_dimens	*get_matrix_dimes(float **map_matrix, t_map *map);

/* convert_matrix.c */
void			get_map_scale(t_map *map);
float			**scale_dimes_matrix(t_map *map, float **map_matrix, t_matrix_dimens *matrix_dimes);

/* draw_line.c */
void			draw_line(mlx_image_t *img, float **convert_matrix, int start, int end);

#endif
