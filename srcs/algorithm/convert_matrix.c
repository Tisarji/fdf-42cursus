/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:47:58 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 18:28:15 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	get_map_scale(t_map *map)
{
	float	big;
	float	scale;

	if (map->height > map->width)
		big = map->height;
	else
		big = map->width;
	scale = WIDTH / (big * 1.7);
	map->scale = scale;
	return ;
}

float	**scale_dimes_matrix(t_map *map, float **map_matrix, t_matrix_dimens *matrix_dimes)
{
	int		x;
	int		y;
	float	scale;
	float	**convert_matrix;

	x = 0;
	scale = map->scale;
	convert_matrix = malloc(sizeof(float *) * (map->height * map->width + 2));
	while (map != NULL)
	{
		y = 0;
		convert_matrix[x] = malloc(sizeof(float) * 2);
		convert_matrix[x][y] = (map_matrix[x][y] * scale) + (WIDTH / 2) - (matrix_dimes->matrix_width / 2 * scale);
		convert_matrix[x][y + 1] = (map_matrix[x][y + 1] * scale) + (HEIGHT / 2) - (matrix_dimes->matrix_height / 2 * scale);
		x++;
		map = map->next;
	}
	convert_matrix[x] = NULL;
	free_matrix(map_matrix);
	free(matrix_dimes);
	return (convert_matrix);
}
