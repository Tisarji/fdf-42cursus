/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:34:39 by jikarunw          #+#    #+#             */
/*   Updated: 2024/06/10 04:48:41 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		ft_error("Usage: ./fdf <filename>", 0);
	parse_map_file(argv[1]);
	fdf = initialize_fdf(argv[1]);
	mlx_loop_hook(fdf->mlx, window_close, fdf);
	render(fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	free_fdf(fdf);
}
