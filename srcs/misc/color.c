/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 20:23:22 by jikarunw          #+#    #+#             */
/*   Updated: 2024/05/27 15:47:19 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	gradient_color(int y1, int y2, int step, int steps)
{
	t_color	color;

	if (y1 == y2)
		return (y1);
	if (!steps)
		return (y1);
	color.r1 = y1 >> 24;
	color.g1 = y1 >> 16;
	color.b1 = y1 >> 8;
	color.r2 = y2 >> 24;
	color.g2 = y2 >> 16;
	color.b2 = y2 >> 8;
	if (color.r1 < color.r2)
		color.r1 += step * (color.r2 - color.r1) / steps;
	else
		color.r1 -= step * (color.r1 - color.r2) / steps;
	if (color.g1 < color.g2)
		color.g1 += step * (color.g2 - color.g1) / steps;
	else
		color.g1 -= step * (color.g1 - color.g2) / steps;
	if (color.b1 < color.b2)
		color.b1 += step * (color.b2 - color.b1) / steps;
	else
		color.b1 -= step * (color.b1 - color.b2) / steps;
	return (color.r1 << 24 | color.g1 << 16 | color.b1 << 8 | 0xFF);
}
