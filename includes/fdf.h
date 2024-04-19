/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:39:09 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/18 14:26:24 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 1920
# define HEIGHT 1080

# include <math.h>
# include <fcntl.h>

# include "./MLX42/include/MLX42/MLX42.h"
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
# include "./libft/includes/ft_printf.h"

typedef struct s_fdfmap
{
	int				z;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;
	int				x_draw;
	int				y_draw;
}					t_fdfmap;

typedef struct s_fdfvariables
{
	t_fdfmap	*map;
	mlx_image_t	*img;
	mlx_image_t	*menu;
	mlx_t		*mlx;
	int			map_width;
	int			map_height;
	int			window_width;
	int			window_height;
	int			z_max;
	int			zoom;
	float		z_zoom;
	float		x_zoom;
	double		radians;
	double		radians2;
	char		view;
}					t_fdfvariables;

#endif
