/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dims.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:12:21 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 18:06:46 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// t_matrix_width	*get_matrix_width(float **map_matrix, t_map *map)
// {
// 	t_matrix_width	*matrix_width;
// 	int				x;
// 	int				y;

// 	x = 0;
// 	matrix_width = malloc(sizeof(float) * 3);
// 	matrix_width->min_width = 0;
// 	matrix_width->max_width = 0;
// 	while (map)
// 	{
// 		y = 0;
// 		if (map_matrix[x][y] < matrix_width->min_width)
// 			matrix_width->min_width = map_matrix[x][y];
// 		if (map_matrix[x][y] > matrix_width->max_width)
// 			matrix_width->max_width = map_matrix[x][y];
// 		x++;
// 		map = map->next;
// 	}
// 	if (matrix_width->min_width < 0)
// 		matrix_width->width = matrix_width->max_width + matrix_width->min_width;
// 	else
// 		matrix_width->width = matrix_width->max_width - matrix_width->min_width;
// 	return (matrix_width);
// }

// t_matrix_height	*get_matrix_height(float **map_matrix, t_map *map)
// {
// 	t_matrix_height	*matrix_height;
// 	int				x;
// 	int				y;

// 	x = 0;
// 	matrix_height = malloc(sizeof(float) * 3);
// 	matrix_height->min_height = 0;
// 	matrix_height->max_height = 0;
// 	while (map)
// 	{
// 		y = 0;
// 		if (map_matrix[x][y] < matrix_height->min_height)
// 			matrix_height->min_height = map_matrix[x][y];
// 		if (map_matrix[x][y] > matrix_height->max_height)
// 			matrix_height->max_height = map_matrix[x][y];
// 		x++;
// 		map = map->next;
// 	}
// 	if (matrix_height->min_height < 0)
// 		matrix_height->height = matrix_height->max_height + matrix_height->min_height;
// 	else
// 		matrix_height->height = matrix_height->max_height - matrix_height->min_height;
// 	return (matrix_height);
// }

// t_matrix_dimens	*get_matrix_dimes(float **map_matrix, t_map *map)
// {
// 	t_matrix_dimens	*matrix_dimes;
// 	t_matrix_height *matrix_height;
// 	t_matrix_width	*matrix_width;

// 	matrix_height = get_matrix_height(map_matrix, map);
// 	matrix_width = get_matrix_width(map_matrix, map);
// 	matrix_dimes = malloc(sizeof(float) * 2);
// 	matrix_dimes->matrix_height = matrix_height->height;
// 	matrix_dimes->matrix_width = matrix_width->width;
// 	free(matrix_height);
// 	free(matrix_width);
// 	return (matrix_dimes);
// }

t_matrix_width	*get_matrix_width(float **map_matrix, t_map *map)
{
	t_matrix_width	*matrix_width;
	int				x;
	int				y;

	x = 0;
	matrix_width = malloc(sizeof(float) * 3);
	matrix_width->min_width = 0;
	matrix_width->max_width = 0;
	while (map)
	{
		y = 0;
		if (map_matrix[x][y] < matrix_width->min_width)
			matrix_width->min_width = map_matrix[x][y];
		if (map_matrix[x][y] > matrix_width->max_width)
			matrix_width->max_width = map_matrix[x][y];
		x++;
		map = map->next;
	}
	if (matrix_width->min_width < 0)
		matrix_width->width = matrix_width->max_width
			+ matrix_width->min_width;
	else
		matrix_width->width = matrix_width->max_width
			- matrix_width->min_width;
	return (matrix_width);
}

t_matrix_height	*get_matrix_height(float **map_matrix, t_map *map)
{
	t_matrix_height	*matrix_height;
	int				x;
	int				y;

	x = 0;
	matrix_height = malloc(sizeof(float) * 3);
	matrix_height->min_height = 0;
	matrix_height->max_height = 0;
	while (map)
	{
		y = 1;
		if (map_matrix[x][y] < matrix_height->min_height)
			matrix_height->min_height = map_matrix[x][y];
		if (map_matrix[x][y] > matrix_height->max_height)
			matrix_height->max_height = map_matrix[x][y];
		x++;
		map = map->next;
	}
	if (matrix_height->min_height < 0)
		matrix_height->height = matrix_height->max_height
			+ matrix_height->min_height;
	else
		matrix_height->height = matrix_height->max_height
			- matrix_height->min_height;
	return (matrix_height);
}

t_matrix_dimens	*get_matrix_dimes(float **map_matrix, t_map *map)
{
	t_matrix_dimens		*matrix_dimes;
	t_matrix_height		*matrix_height;
	t_matrix_width		*matrix_width;

	matrix_width = get_matrix_width(map_matrix, map);
	matrix_height = get_matrix_height(map_matrix, map);
	matrix_dimes = malloc(sizeof(float) * 2);
	matrix_dimes->matrix_height = matrix_height->height;
	matrix_dimes->matrix_width = matrix_width->width;
	free(matrix_height);
	free(matrix_width);
	return (matrix_dimes);
}
