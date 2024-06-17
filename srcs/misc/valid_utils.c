/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 13:07:41 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 05:09:15 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int validate_line_count(int fd, int size)
{
	int check;
	char *line;
	char **split_line;
	int current_line_size;

	check = true;
	current_line_size = 0;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		split_line = ft_split(line, ' ');
		while (split_line[current_line_size] && split_line[current_line_size][0] != '\n')
			current_line_size++;
		if (current_line_size != size)
			check = false;
		current_line_size = 0;
		free(line);
		free_split(split_line);
	}
	close(fd);
	get_next_line(-1);
	return (check);
}

uint32_t apply_alpha(uint32_t color)
{
	uint32_t new_color;
	unsigned char *ptr;

	new_color = color << 8;
	ptr = (unsigned char *)&new_color;
	*ptr = 255;
	return (new_color);
}

void handle_invalid_map(t_fdf *fdf, t_map *map)
{
	free(fdf);
	free(map);
	ft_error("Error: invalid map", 0);
}

float calculate_scale(t_fdf *fdf)
{
	float	scale;
	float	scale_x;
	float	scale_y;

	scale_x = WIDTH / (float)fdf->map->width;
	scale_y = HEIGHT / (float)fdf->map->height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale / 1.3);
}

void center_map(t_map *map)
{
	unsigned short x;
	unsigned short y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->matrix[y][x].x -= map->width / 2;
			map->matrix[y][x].y -= map->height / 2;
			x++;
		}
		y++;
	}
}
