/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:30:16 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/17 09:22:45 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void draw_bresenham_line(t_fdf *fdf, t_point start, t_point end)
{
	int dx = ft_abs((int)end.x - (int)start.x);
	int dy = ft_abs((int)end.y - (int)start.y);
	int sx = start.x < end.x ? 1 : -1;
	int sy = start.y < end.y ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		put_pixel(fdf, (int)start.x, (int)start.y, start.color);
		if ((int)start.x == (int)end.x && (int)start.y == (int)end.y)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			start.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			start.y += sy;
		}
	}
}

static void draw_dda_line(t_fdf *fdf, t_point start, t_point end)
{
	float	dx;
	float	dy;
	int		steps;
	float	xIncrement; 
	float	yIncrement; 

	float x = start.x;
	float y = start.y;
	dx = end.x - start.x;
	dy = end.y - start.y;
	if (ft_abs(dx) > ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;

	int i = 0;
	while (i++ <= steps)
	{
		put_pixel(fdf, (int)x, (int)y, start.color);
		x += xIncrement;
		y += yIncrement;
	}
}


void draw_line(t_fdf *fdf, t_point start, t_point end)
{
	float dx = end.x - start.x;
	float dy = end.y - start.y;
	float slope = ft_abs(dy / dx);

	if (slope < SLOPE_THRESHOLD)
		draw_dda_line(fdf, start, end);
	else
		draw_bresenham_line(fdf, start, end);
}
