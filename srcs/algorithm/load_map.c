/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:47:58 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/12 11:04:50 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int get_map_width(char *map_name)
{
	int size;
	int fd;
	char *line;
	char **split_line;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	size = 0;
	while (split_line[size] && split_line[size][0] != '\n')
		size++;
	free(line);
	free_split(split_line);
	if (!validate_line_count(fd, size))
		return (0);
	return (size);
}

static int get_map_height(char *map_name)
{
	int fd;
	char *line;
	int height;

	height = 0;
	fd = open(map_name, O_RDONLY);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static void parse_line(t_map *map, char **split_line, int line_index)
{
	int column_index;
	char *color;

	column_index = 0;
	while (column_index < map->width)
	{
		map->matrix[line_index][column_index].x = (float)column_index;
		map->matrix[line_index][column_index].y = (float)line_index;
		map->matrix[line_index][column_index].z = (float)(ft_atoi(split_line[column_index]));
		if (map->matrix[line_index][column_index].z > map->z_max)
			map->z_max = map->matrix[line_index][column_index].z;
		color = ft_strchr(split_line[column_index], ',');
		if (color)
			map->matrix[line_index][column_index].color = apply_alpha(ft_hex_to_dec(color + 1));
		else
		{
			if (map->matrix[line_index][column_index].z <= 0)
				map->matrix[line_index][column_index].color = 0xffffffff;
			else
				map->matrix[line_index][column_index].color = 0xffffffff;
		}
		column_index++;
	}
}

static void convert_matrix(t_map *map, char *map_name)
{
	char *line;
	char **split_line;
	int line_index;
	int fd;

	fd = open(map_name, O_RDONLY);
	line_index = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		split_line = ft_split(line, ' ');
		parse_line(map, split_line, line_index);
		free_split(split_line);
		free(line);
		line_index++;
	}
}

t_map *load_map(t_fdf *fdf, char *map_name)
{
	t_map *map;

	map = initialize_map();
	map->width = get_map_width(map_name);
	map->height = get_map_height(map_name);
	if (map->width < 2 || map->height < 2)
		handle_invalid_map(fdf, map);
	map->matrix = allocate_matrix(map->width, map->height);
	convert_matrix(map, map_name);
	center_map(map);
	return (map);
}
