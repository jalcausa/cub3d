/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:21:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/11 20:09:17 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_loop_handler(void *param)
{
	(void) param;
}

void	ft_init_game(t_game *info)
{
	ft_init_player(info->player, info);
	//mlx_key_hook(info->mlx, &ft_controls, info);
	mlx_loop_hook(info->mlx, &ft_loop_handler, info);
	mlx_loop(info->mlx);
}

int	ft_check_monitor(mlx_t *mlx)
{
	int32_t	w;
	int32_t	h;

	mlx_get_monitor_size(0, &w, &h);
	if (w < WIDTH || h < HEIGHT)
	{
		ft_printf("monitor invalido\n");
		mlx_terminate(mlx);
		return (0);
	}
	return (1);
}

int	ft_set_window(t_game *info)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	info->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!info->mlx)
		ft_printf("Error\n");
	if (ft_check_monitor(info->mlx) == 0)
		return (-1);
	mlx_set_window_limit(info->mlx, 500, 500, 2560, 1440);
	return (0);
}

int	main(void)
{
	t_game		info;
	t_scene		scene;
	t_player	player;
	t_img		imgs;

	// Inicializar todo a cero
	ft_memset(&scene, 0, sizeof(t_scene));
	ft_memset(&player, 0, sizeof(t_player));
	ft_memset(&imgs, 0, sizeof(t_img));
	
	// Crear un mapa de prueba simple
	static char *test_map[] = {
		"111111",
		"1N0001",
		"100001",
		"100001",
		"100001",
		"111111",
		NULL
	};
	
	// Inicializar scene con valores de prueba
	scene.map = test_map;
	scene.len_x = 6;
	scene.len_y = 6;
	
	// Asignar punteros
	info.scene = &scene;
	info.player = &player;
	info.imgs = &imgs;
	
	if (ft_set_window(&info) != -1)
	{
		ft_init_game(&info);
		mlx_terminate(info.mlx);
	}
	return (0);
}
