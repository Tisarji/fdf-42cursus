/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:46:21 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 04:29:13 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	parse_map_file(char *argv)
{
	int		fd;
	char	*content;

	if (ft_strnstr(argv, ".fdf", ft_strlen(argv)) == NULL)
		ft_error("Error: invalid file", 0);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Error: open failed", 0);
	content = get_next_line(fd);
	if (content == NULL)
		ft_error("Error: empty file", 0);
	free(content);
	get_next_line(-1);
	close(fd);
}
