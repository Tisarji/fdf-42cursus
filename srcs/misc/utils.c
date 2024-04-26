/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:02:29 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 18:30:49 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_draw_line	*new_line(mlx_image_t *img, float **convert_matrix, int start, int end)
{
	t_draw_line	*line;

	line = malloc(sizeof(t_draw_line));
	line->img = img;
	line->dx = ft_abs(convert_matrix[end][0] - convert_matrix[start][0]);
	line->dy = ft_abs(convert_matrix[end][1] - convert_matrix[start][1]);
	line->control = 0;
	
	if (convert_matrix[end][0] > convert_matrix[start][0])
		line->offset_x = 1;
	else
		line->offset_x = -1;
	if (convert_matrix[end][1] > convert_matrix[start][1])
		line->offset_y = 1;
	else
		line->offset_y = -1;
	return (line);
}

// * Background Color "0x00000FF"

void	draw_background(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx_put_pixel(img, x, y, 0x00000FF);
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x <= 0 || y <= 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	mlx_put_pixel(img, x, y, color);
}
