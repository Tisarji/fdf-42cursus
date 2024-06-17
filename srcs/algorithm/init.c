/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:29:51 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 04:45:49 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf *initialize_fdf(char *map_name)
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		ft_error("Error: malloc failed", 0);
	fdf->map = load_map(fdf, map_name);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "🧠💥 FDF - jikarunw", 1);
	if (!fdf->mlx)
		ft_error("Error: mlx_init failed", 0);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		ft_error("Error: mlx_new_image failed", 0);
	fdf->scale = initialize_camera(fdf);
	mlx_image_to_window(fdf->mlx, fdf->img, 0, 0);
	return (fdf);
}

t_map *initialize_map(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Error: malloc failed", 0);
	map->width = 0;
	map->height = 0;
	map->z_max = 0;
	map->matrix = NULL;
	return (map);
}

t_scale *initialize_camera(t_fdf *fdf)
{
	t_scale *matrix;

	matrix = malloc(sizeof(t_scale));
	if (!matrix)
		ft_error("Error: malloc failed", 0);
	matrix->scale = calculate_scale(fdf);
	matrix->x_offset = (WIDTH / 2);
	matrix->y_offset = (HEIGHT / 2);
	matrix->z_scale = 1;
	if (fdf->map->z_max <= 20)
		matrix->z_scale = 10;
	else if (fdf->map->z_max > 720)
		matrix->z_scale = 0.03;
	return (matrix);
}
