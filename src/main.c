/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:21:10 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/26 14:29:27 by yz               ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game		info;
	t_scene		scene;
	t_player	player;
	t_img		imgs;
	int			fd;

	ft_init_structs(&info, &imgs);
	fd = ft_arg_check(argc, argv);
	if (fd < 0)
		return (-1);
	if (ft_parse(&scene, fd, argv[1], &imgs) != -1)
	{
		info.scene = &scene;
		info.player = &player;
		info.imgs = &imgs;
		if (ft_set_window(&info) != -1)
		{
			ft_init_game(&info);
			mlx_terminate(info.mlx);
		}
		ft_clean_map(&info);
	}
	return (0);
}
