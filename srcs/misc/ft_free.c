/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:34:31 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 04:29:25 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_fdf(t_fdf *fdf)
{
	free_matrix(fdf->map);
	free(fdf->map);
	free(fdf->scale);
	free(fdf);
}

void	free_matrix(t_map *map)
{
	while (map->height--)
		free(map->matrix[map->height]);
	free(map->matrix);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}
