/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 20:31:49 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/04 00:15:47 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int32_t	ft_w_center(const uint32_t n1, const uint32_t n2)
{
	if (n1 > n2)
		return ((n1 - n2) / 2);
	return ((n2 - n1) / 2);
}

int32_t	main(int argc, char **argv)
{
	t_fdfvariables	fdf;

	if (argc != 2 || !argv[1])
		return (1);
	ft_map_construct(argv[1], &fdf);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF - jikarunw", true);
	if (!fdf.mlx)
		ft_error("MLX INIT FAIL.", 1, fdf.map);
	fdf.img = mlx_new_image(fdf.mlx, fdf.window_width, fdf.window_height);
	if (!fdf.img)
		ft_error("MLX NEW IMAGE FAIL.", 1, fdf.map);
	ft_render(&fdf);
	if (mlx_image_to_window(fdf.mlx, fdf.img, \
	ft_w_center(WIDTH, fdf.img->width), ft_w_center(HEIGHT, fdf.img->height)))
		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, fdf.map);
	ft_menu(&fdf);
	mlx_loop_hook(fdf.mlx, &keyboard_hooks, (void *)&fdf);
	mlx_scroll_hook(fdf.mlx, &scroll_hook, (void *)&fdf);
	mlx_cursor_hook(fdf.mlx, &cursor_hook, (void *)&fdf);
	mlx_loop(fdf.mlx);
	ft_multiple_free(1, fdf.map);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
