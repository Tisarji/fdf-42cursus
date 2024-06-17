/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:35:33 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/16 15:01:32 by jikarunw         ###   ########.fr       */
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

# define SLOPE_THRESHOLD 1.0

#define BASE_LOW "0123456789ABCDEF"
#define BASE_UPPER "0123456789abcdef"

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	uint32_t	color;
}				t_point;

typedef struct s_map
{
	t_point		**matrix;
	int			width;
	int			height;
	float		z_max;
}				t_map;

typedef struct s_scale
{
	float		scale;
	float		x_offset;
	float		y_offset;
	float		z_scale;
}				t_scale;

typedef struct s_draw_line
{
	int			dx;
	int			dy;
	int			control;
	int			inc_x;
	int			inc_y;
}				t_draw_line;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	t_scale		*scale;
}				t_fdf;

/***********************
 *   SECTION - FREE    *
 * PATH DIR: SRCS/MISC *
 ***********************/

/* utils_01.c */
void			initialize_line_data(t_draw_line *line, t_point start, t_point end);
t_point			**allocate_matrix(int width, int height);
void			draw_background(t_fdf *fdf);
void			put_pixel(t_fdf *fdf, int x, int y, uint32_t color);
void			window_close(void *param);

/* utils_02.c */
int				validate_line_count(int fd, int expected_line_count);
uint32_t		apply_alpha(uint32_t color);
void			handle_invalid_map(t_fdf *fdf, t_map *map);
float			calculate_scale(t_fdf *fdf);
void			center_map(t_map *map);

/* parser.c */
void			parse_map_file(char *file_path);

/* ft_free.c */
void			free_fdf(t_fdf *fdf);
void			free_matrix(t_map *map);
void			free_split(char **split);

/****************************
 *   SECTION - ALGORITHM    *
 * PATH DIR: SRCS/ALGORITHM *
 ****************************/

/* render.c */
void			render(t_fdf *fdf);
void			transform_points(t_fdf *fdf, t_point start, t_point end);
void			scale_points(t_fdf *fdf, t_point *start, t_point *end);
void			convert_to_isometric(t_fdf *fdf, t_point *start, t_point *end);
void			centralize_points(t_fdf *fdf, t_point *start, t_point *end);


/* map_read.c */
t_fdf			*initialize_fdf(char *map_name);
t_map			*initialize_map(void);
t_scale			*initialize_camera(t_fdf *fdf);

/* get_dims.c */


/* convert_matrix.c */
t_map			*load_map(t_fdf *fdf, char *map_name);

/* draw_line.c */
void			draw_line(t_fdf *fdf, t_point start, t_point end);

#endif
