/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:34:31 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/23 22:31:14 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_data(t_map *data)
{
	t_map	*temp;

	while (data != NULL)
	{
		temp = data;
		data = data->next;
		if (temp->s_coord != NULL)
		{
			free(temp->s_coord);
			temp->s_coord = NULL;
		}
		free(temp);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_matrix(float **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}
