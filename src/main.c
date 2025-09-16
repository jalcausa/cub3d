/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:21:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/13 20:44:41 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
mod is a modifier that can change the position from where the ray is sent.
*/
void	ft_loop_handler(void *param)
{
	t_game	*info;
	t_coll	coll;
	int		i;
	double	player_angle;
	t_coord	mod;

	mod.x = 0;
	mod.y = 0;
	info = (t_game *)param;
	ft_redisplay(info);
	player_angle = ft_deg_to_rad(info->player->angle);
	i = 0;
	while (i < WIDTH)
	{
		coll = ft_ray_caster(info, ft_rayangle(i, player_angle), &mod);
		ft_draw_col(info, WALL_H / coll.distance, i, &coll);
		i++;
	}
}

void	ft_init_game(t_game *info)
{
	ft_init_player(info->player, info);
	mlx_key_hook(info->mlx, &ft_controls, info);
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
	
	// Crear un mapa de prueba simple
	static char *test_map[] = {
		"111111",
		"100001",
		"10N001",
		"101101",
		"100101",
		"111111",
		NULL
	};
	
	// Inicializar scene con valores de prueba
	scene.map = test_map;
	scene.len_x = 6;
	scene.len_y = 6;
	scene.tile = 10.0;  // Tamaño de cada celda del mapa
	scene.floor = 0x654321FF;    // Color marrón para el suelo
	scene.ceiling = 0x87CEEBFF;  // Color azul cielo para el techo
	
	// Rutas de texturas
	scene.no_path = "/Users/jalcausa/Documents/42/cub3d/textures/bluestone.png";
	scene.so_path = "/Users/jalcausa/Documents/42/cub3d/textures/greystone.png"; 
	scene.ea_path = "/Users/jalcausa/Documents/42/cub3d/textures/purplestone.png";
	scene.we_path = "/Users/jalcausa/Documents/42/cub3d/textures/redbrick.png";
	
	// Asignar punteros
	info.scene = &scene;
	info.player = &player;
	info.imgs = &imgs;
	
	// Primero inicializar MLX
	if (ft_set_window(&info) == -1)
	{
		ft_printf("Error: No se pudo inicializar la ventana\n");
		return (-1);
	}

	// Luego cargar texturas
	if (ft_load_images(&scene, &imgs) == -1)
	{
		ft_printf("Error: No se pudieron cargar las texturas\n");
		ft_printf("Verificar que existan los archivos:\n");
		ft_printf("- %s\n", scene.no_path);
		ft_printf("- %s\n", scene.so_path);
		ft_printf("- %s\n", scene.ea_path);
		ft_printf("- %s\n", scene.we_path);
		mlx_terminate(info.mlx);
		return (-1);
	}
	
	// Finalmente inicializar el juego
	ft_init_game(&info);
	mlx_terminate(info.mlx);
	return (0);
}
