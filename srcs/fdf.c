/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:34:39 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/28 13:57:15 by Tisarji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	key_hooks(mlx_key_data_t keydata, void *mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}

static void	init_help_mlx(mlx_t *mlx)
{
	mlx_key_hook(mlx, &key_hooks, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return ;
}

int	main(int argc, char **argv)
{
	t_map		*map;
	mlx_t		*mlx;
	mlx_image_t	*img;

	if (argc != 2 || ft_parser_map(argv[1]))
		ft_error("usage:./fdf [map]", 0);
	map = map_read(argv[1]);
	if (!(map))
		ft_error("File has no content!", 0);
	mlx = mlx_init(WIDTH, HEIGHT, "FDF - jikarunw", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, img, 0, 0);
	render(map, img);
	init_help_mlx(mlx);
	free_data(map);
	return (0);
}
