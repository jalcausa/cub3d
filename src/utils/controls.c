/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:29:56 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/12 13:29:50 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_collision(t_game *game, double new_x, double new_y)
{
	int	map_x;
	int	map_y;
	
	// Convertir coordenadas del mundo a coordenadas del mapa
	map_x = (int)new_x;
	map_y = (int)new_y;
	
	// Verificar límites del mapa
	if (map_x < 0 || map_x >= game->scene->len_x || 
		map_y < 0 || map_y >= game->scene->len_y)
		return (1); // Colisión con límite
	
	// Verificar si la nueva posición está en una pared
	if (game->scene->map[map_y][map_x] == '1')
		return (1); // Colisión con pared
		
	return (0); // No hay colisión
}

void	ft_ws(t_player *player, double dir, t_game *game, float angle)
{
	double	new_x;
	double	new_y;
	
	(void)angle; // Suprimir advertencia de parámetro no usado
	
	// Calcular nueva posición
	new_x = player->pos->x + (dir * cos(ft_deg_to_rad(player->angle)) * player->mov_speed) / game->scene->tile;
	new_y = player->pos->y + (dir * sin(ft_deg_to_rad(player->angle)) * player->mov_speed) / game->scene->tile;
	
	// Solo mover si no hay colisión
	if (!ft_collision(game, new_x, new_y))
	{
		player->pos->x = new_x;
		player->pos->y = new_y;
	}
}


void	ft_ad(t_player *player, double dir, double ang, t_game *game)
{
	int		rot;
	double	new_x;
	double	new_y;

	(void)dir; // Suprimir advertencia de parámetro no usado
	rot = player->angle + ang;
	
	// Calcular nueva posición
	new_x = player->pos->x + (cos(ft_deg_to_rad(rot)) * player->mov_speed) / game->scene->tile;
	new_y = player->pos->y + (sin(ft_deg_to_rad(rot)) * player->mov_speed) / game->scene->tile;
	
	// Solo mover si no hay colisión
	if (!ft_collision(game, new_x, new_y))
	{
		player->pos->x = new_x;
		player->pos->y = new_y;
	}
}

void	ft_rotate(t_player *player, double sign, t_game *game)
{
	float	ang;

	(void)ang;  // Suprimir advertencia de variable no usada
	(void)game; // Suprimir advertencia de parámetro no usado
	player->angle += sign * player->rot_speed;
	if (player->angle < 0)
		player->angle += 360;
	if (player->angle >= 360)
		player->angle = player->angle % 360;
}

void	ft_controls(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	(void)keydata; // Suprimir advertencia de parámetro no usado
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
