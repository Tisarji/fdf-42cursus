/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:46:21 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/25 00:20:38 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	valid_file(const char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}

int	ft_parser_map(const char *argv)
{
	int			name_len;
	const char	*format;
	int 		format_len;
	int			start_index;

	name_len = ft_strlen(argv);
	format = ".fdf";
	format_len = ft_strlen(format);
	if (name_len >= format_len)
	{
		start_index = name_len - format_len;
		if (!(ft_strncmp(argv + start_index, format, format_len)))
		{
			if (!(valid_file(argv)))
				return (0);
		}
	}
	return (1);
}
