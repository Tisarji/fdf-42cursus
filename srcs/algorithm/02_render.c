/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 17:28:36 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/03 17:29:57 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

void	remake(int reset, t_fdfvariables *fdf)
{
	if (reset == 0)
	{
		fdf->z_max = 0;
		fdf->zoom = 0;
		fdf->z_zoom = 0.4;
		fdf->x_zoom = 1;
		fdf->radians = 0;
		fdf->radians2 = 0;
	}
	ft_views(fdf);
	mlx_resize_image(fdf->img, fdf->window_width, fdf->window_height);
	ft_render(fdf);
}

void	ft_render_brush(uint8_t r, uint8_t g, uint8_t b, t_fdfmap	*map)
{
	map->r = r;
	map->g = g;
	map->b = b;
	map->a = 255;
}

void	ft_render_basic_colors(int colors, t_fdfvariables *fdf)
{
	int	i;

	i = -1;
	if (colors == 1)
		while (++i < (fdf->map_height * fdf->map_width))
			ft_render_brush(255, 140, 0, &fdf->map[i]);
	else if (colors == 2)
		while (++i < (fdf->map_height * fdf->map_width))
			ft_render_brush(255, 255, 255, &fdf->map[i]);
	else if (colors == 3)
		while (++i < (fdf->map_height * fdf->map_width))
			ft_render_brush(0, 0, 0, &fdf->map[i]);
}

void	ft_render_colors(int colors, t_fdfvariables *fdf)
{
	int	i;
	int	aux;

	i = -1;
	aux = 0;
	if (colors == 0)
	{
		while (++i < (fdf->map_height * fdf->map_width))
		{
			if (fdf->z_max != 0)
				aux = fdf->map[i].z * 60 / fdf->z_max;
			if (fdf->map[i].z == fdf->z_max)
				ft_render_brush(255, 255, 255, &fdf->map[i]);
			else if (fdf->map[i].z >= 0)
				ft_render_brush(80, 100 - aux, 0, &fdf->map[i]);
			else if (fdf->map[i].z < 0)
				ft_render_brush(0, 0, 128, &fdf->map[i]);
		}
	}
	else
		ft_render_basic_colors(colors, fdf);
	remake(1, fdf);
}
