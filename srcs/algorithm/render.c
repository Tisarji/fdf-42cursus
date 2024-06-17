/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:44:50 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 04:47:16 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void render(t_fdf *fdf)
{
	int x;
	int y;

	draw_background(fdf);
	y = 0;
	while (y + 1 <= fdf->map->height)
	{
		x = 0;
		while (x + 1 <= fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				transform_points(fdf, fdf->map->matrix[y][x], fdf->map->matrix[y][x + 1]);
			if (y + 1 < fdf->map->height)
				transform_points(fdf, fdf->map->matrix[y][x], fdf->map->matrix[y + 1][x]);
			x++;
		}
		y++;
	}
}

void transform_points(t_fdf *fdf, t_point start, t_point end)
{
	scale_points(fdf, &start, &end);
	convert_to_isometric(fdf, &start, &end);
	centralize_points(fdf, &start, &end);
	draw_line(fdf, start, end);
}

void scale_points(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x *= fdf->scale->scale;
	end->x *= fdf->scale->scale;
	start->y *= fdf->scale->scale;
	end->y *= fdf->scale->scale;
}

void convert_to_isometric(t_fdf *fdf, t_point *start, t_point *end)
{
	t_point new_start;
	t_point new_end;

	new_start.x = (start->x - start->y) * cos(0.86602540378);
	new_start.y = (start->x + start->y) * sin(0.5) - (start->z * fdf->scale->z_scale);
	new_end.x = (end->x - end->y) * cos(0.86602540378);
	new_end.y = (end->x + end->y) * sin(0.5) - (end->z * fdf->scale->z_scale);
	start->x = new_start.x;
	start->y = new_start.y;
	end->x = new_end.x;
	end->y = new_end.y;
}

void centralize_points(t_fdf *fdf, t_point *start, t_point *end)
{
	start->x += fdf->scale->x_offset;
	start->y += fdf->scale->y_offset;
	end->x += fdf->scale->x_offset;
	end->y += fdf->scale->y_offset;
}
