/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:02:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 04:28:19 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void initialize_line_data(t_draw_line *line, t_point start, t_point end)
{
	line->dx = ft_abs(end.x - start.x);
	line->dy = ft_abs(end.y - start.y);
	line->control = 0;
	if (end.x > start.x)
		line->inc_x = 1;
	else
		line->inc_x = -1;
	if (end.y > start.y)
		line->inc_y = 1;
	else
		line->inc_y = -1;
}

t_point **allocate_matrix(int width, int height)
{
	t_point **matrix;

	matrix = malloc(height * sizeof(t_point *));
	if (!matrix)
		ft_error("Error: malloc failed", 0);
	while (height--)
	{
		matrix[height] = ft_calloc(width, sizeof(t_point));
		if (!matrix[height])
			ft_error("Error: malloc failed", 0);
	}
	return (matrix);
}

void draw_background(t_fdf *fdf)
{
	uint32_t *pixel;
	uint32_t idx;

	pixel = (uint32_t *)fdf->img->pixels;
	idx = fdf->img->height * fdf->img->width;
	while (idx--)
		pixel[idx] = 0xff000000;
}

void put_pixel(t_fdf *fdf, int x, int y, uint32_t color)
{
	if (x <= 0 || y <= 0 || x >= WIDTH || y >= HEIGHT)
		return;
	mlx_put_pixel(fdf->img, x, y, color);
}

void	window_close(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
}
