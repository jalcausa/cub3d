/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 19:27:45 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/11 19:58:29 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_get_player_angle(t_scene *scene)
{
	int	y;
	int	x;

	y = 0;
	while (scene->map[y])
	{
		x = 0;
		while (scene->map[y][x])
		{
			if (scene->map[y][x] == 'E')
				return (0.0);
			if (scene->map[y][x] == 'S')
				return (90.0);
			if (scene->map[y][x] == 'W')
				return (180.0);
			if (scene->map[y][x] == 'N')
				return (270.0);
			x++;
		}
		y++;
	}
	return (-1);
}


/*
The player is positioned in the middle of the cell, that's why we add 0.5 to the coordenates
*/
t_coord	ft_get_player_init_pos(t_game *game)
{
	t_coord	pos;
	int		y;
	int		x;

	y = 0;
	while (game->scene->map[y])
	{
		x = 0;
		while (game->scene->map[y][x])
		{
			if (ft_strchr("NSEW", game->scene->map[y][x]))
			{
				pos.x = x;
				pos.y = y;
			}
			x++;
		}
		y++;
	}
	pos.x += 0.5;
	pos.y += 0.5;
	return (pos);
}

void	ft_init_player(t_player *player, t_game *game)
{
	player->mlx = game->mlx;
	player->pos = malloc(sizeof(t_coord));
	if (!player->pos)
	{
		ft_printf("Error: malloc failed for player position\n");
		return ;
	}
	*player->pos = ft_get_player_init_pos(game);
	player->mov_speed = 0.5;
	player->rot_speed = 2.0;
	player->angle = ft_get_player_angle(game->scene);
}
