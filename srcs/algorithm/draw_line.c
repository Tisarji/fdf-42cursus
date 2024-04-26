/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:30:16 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 18:28:32 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	draw_vertical(t_draw_line *line, float **convert_matrix, int start, int end);
static void	draw_horizontal(t_draw_line *line, float **convert_matrix, int start, int end);
static void	draw_line_x_axis(t_draw_line *line, float **convert_matrix, int start, int end);
static void	draw_line_y_axis(t_draw_line *line, float **convert_matrix, int start, int end);

void	draw_line(mlx_image_t *img, float **convert_matrix, int start, int end)
{
	t_draw_line	*line;

	line = new_line(img, convert_matrix, start, end);
	if (line->dx == 0)
		draw_vertical(line, convert_matrix, start, end);
	else if (line->dy == 0)
		draw_horizontal(line, convert_matrix, start, end);
	else
	{
		if (line->dx >= line->dy)
			draw_line_x_axis(line, convert_matrix, start, end);
		else
			draw_line_y_axis(line, convert_matrix, start, end);
	}
	free(line);
}

static void	draw_vertical(t_draw_line *line, float **convert_matrix, int start, int end)
{
	int	y;

	y = 0;
	if ((int)convert_matrix[end][1] > convert_matrix[start][1])
	{
		while ((int)convert_matrix[start][1] != (int)convert_matrix[end][1])
		{
			put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
			convert_matrix[start][1]++;
			y++;
		}
	}
	else
	{
		while ((int)convert_matrix[start][1] != (int)convert_matrix[end][1])
		{
			put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
			convert_matrix[start][1]--;
			y--;
		}
	}
	convert_matrix[start][1] -= y;
}

static void	draw_horizontal(t_draw_line *line, float **convert_matrix, int start, int end)
{
	int	x;

	x = 0;
	if ((int)convert_matrix[end][0] > (int)convert_matrix[start][0])
	{
		while ((int)convert_matrix[start][0] != (int)convert_matrix[end][0])
		{
			put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
			convert_matrix[start][0]++;
			x++;
		}
	}
	else
	{
		while ((int)convert_matrix[start][0] != (int)convert_matrix[end][0])
		{
			put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
			convert_matrix[start][0]--;
			x--;
		}
	}
	convert_matrix[start][0] -= x;
}

static void draw_line_x_axis(t_draw_line *line, float **convert_matrix, int start, int end)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	line->control = line->dx / 2;
	put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
	while ((int)convert_matrix[start][0] != (int)convert_matrix[end][0])
	{
		convert_matrix[start][0] += line->offset_x;
		x += line->offset_x;
		line->control -= line->dy;
		if (line->control < 0)
		{
			convert_matrix[start][1] += line->offset_y;
			y += line->offset_y;
			line->control += line->dx;
		}
		put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
	}
	convert_matrix[start][0] -= x;
	convert_matrix[start][1] -= y;
}

static void draw_line_y_axis(t_draw_line *line, float **convert_matrix, int start, int end)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	line->control = line->dy / 2;
	put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
	while ((int)convert_matrix[start][1] != (int)convert_matrix[end][1])
	{
		convert_matrix[start][1] += line->offset_y;
		y += line->offset_y;
		line->control -= line->dx;
		if (line->control < 0)
		{
			convert_matrix[start][0] += line->offset_x;
			x += line->offset_x;
			line->control += line->dy;
		}
		put_pixel(line->img, (int)convert_matrix[start][0], (int)convert_matrix[start][1], 0xFFFFFFFF);
	}
	convert_matrix[start][0] -= x;
	convert_matrix[start][1] -= y;
}
