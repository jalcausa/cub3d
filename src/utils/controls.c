/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:29:56 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/26 14:25:26 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_collision(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)new_x;
	map_y = (int)new_y;
	if (map_x < 0 || map_x >= game->scene->len_x
		|| map_y < 0 || map_y >= game->scene->len_y)
		return (1);
	if (game->scene->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	ft_ws(t_player *player, double dir, t_game *game, float angle)
{
	double	new_x;
	double	new_y;

	(void)angle;
	new_x = player->pos.x + (dir * cos(ft_deg_to_rad(player->angle))
			* player->mov_speed) / game->scene->tile;
	new_y = player->pos.y + (dir * sin(ft_deg_to_rad(player->angle))
			* player->mov_speed) / game->scene->tile;
	if (!ft_collision(game, new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	int		rot;
	double	new_x;
	double	new_y;

	(void)dir;
	rot = player->angle + ang;
	new_x = player->pos.x + (cos(ft_deg_to_rad(rot))
			* player->mov_speed) / game->scene->tile;
	new_y = player->pos.y + (sin(ft_deg_to_rad(rot))
			* player->mov_speed) / game->scene->tile;
	if (!ft_collision(game, new_x, new_y))
	{
		player->pos.x = new_x;
		player->pos.y = new_y;
	}
}

void	ft_rotate(t_player *player, double sign, t_game *game)
{
	float	ang;

	(void)ang;
	(void)game;
	player->angle += sign * player->rot_speed;
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle >= 360)
		player->angle = player->angle % 360;
}

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	(void)keydata;
	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		ft_ws(game->player, 1.0, game, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		ft_ws(game->player, -1.0, game, 180);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		ft_ad(game->player, -1.0, 270, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		ft_ad(game->player, 1.0, 90, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		ft_rotate(game->player, -1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		ft_rotate(game->player, 1.0, game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}
