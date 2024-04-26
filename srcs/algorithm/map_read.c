/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:29:51 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/26 18:14:46 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*map_read(const char *argv)
{
	t_map	*temp;
	char	*line;
	int		fd;
	int		y;

	fd = open(argv, O_RDONLY);
	y = 0;
	temp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		temp = insert_node(temp, new_list(line, y));
		y++;
		free(line);
	}
	if (temp == NULL)
	{
		free_data(temp);
		return (NULL);
	}
	temp->height = y;
	close(fd);
	return (temp);
}

t_map	*new_list(char *line, int y)
{
	int		x;
	char	**split;
	t_map	*list;

	x = 0;
	list = NULL;
	split = ft_split(line, ' ');
	if (!split)
	{
		free_split(split);
		return (NULL);
	}
	while (split[x])
	{
		list = insert_node(list, new_node(x, y, ft_atoi(split[x])));
		x++;
	}
	list->width = x;
	free_split(split);
	return (list);
}

t_map	*insert_node(t_map *head, t_map *list)
{
	t_map	*current;

	current = head;
	if (!list)
		return (head);
	if (head == NULL)
	{
		head = list;
		current = head;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = list;
		current = current->next;
	}
	return (head);
}

t_map	*new_node(int x, int y, int z)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->s_coord = malloc(sizeof(t_coords));
	if (!node->s_coord)
	{
		free(node);
		return (NULL);
	}
	node->s_coord->x = x;
	node->s_coord->y = y;
	node->s_coord->z = z;
	node->next = NULL;
	return (node);
}
