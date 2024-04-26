/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:44:50 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 17:53:30 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	render(t_map *map, mlx_image_t *img)
{
	float	**map_matrix;
	float	**converted_matrix;

	draw_background(img);
	map_matrix = get_map_matrix(map);
	converted_matrix = convert_matrix(map, map_matrix);
	draw_map(map, img, converted_matrix);
	return ;
}

float	**get_map_matrix(t_map *map)
{
	float	**map_matrix;
	int		x;
	int		y;

	y = 0;
	x = 0;
	map_matrix = malloc(sizeof(float *) * (map->height * map->width + 2));
	while (map != NULL)
	{
		y = 0;
		map_matrix[x] = malloc(sizeof(float) * 2);
		map_matrix[x][y] = (map->s_coord->x - map->s_coord->y) * cos(0.86602540378);
		y++;
		map_matrix[x][y] = (map->s_coord->x + map->s_coord->y) * sin(0.5) - 0.15 * map->s_coord->z;
		x++;
		map = map->next;
	}
	map_matrix[x] = NULL;
	return (map_matrix);
}

float	**convert_matrix(t_map *map, float **map_matrix)
{
	float				**convert_matrix;
	t_matrix_dimens		*s_matrix_dimensions;

	s_matrix_dimensions = get_matrix_dimes(map_matrix, map);
	get_map_scale(map);
	convert_matrix = scale_dimes_matrix(map, map_matrix,
			s_matrix_dimensions);
	return (convert_matrix);
}

void	draw_map(t_map *map, mlx_image_t *img, float **convert_matrix)
{
	int		x;
	int		width;
	int		height;

	x = 0;
	width = map->width;
	height = map->height;
	while (map)
	{
		if ((x + 1) % width != 0)
			draw_line(img, convert_matrix, x, x + 1);
		if (x < (height - 1) * width)
			draw_line(img, convert_matrix, x, x + width);
		x++;
		map = map->next;
	}
	free_matrix(convert_matrix);
}
