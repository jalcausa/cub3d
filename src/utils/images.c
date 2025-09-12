/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:38:42 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/12 13:41:15 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_redisplay(t_game *game)
{
	if (game->scene->canvas)
		mlx_delete_image(game->mlx, game->scene->canvas);
	game->scene->canvas = mlx_new_image(game->mlx, 2560, 1440);
	if (!game->scene->canvas)
		ft_printf("Error\n");
	if (mlx_image_to_window(game->mlx, game->scene->canvas, 0, 0) < 0)
		ft_printf("Error\n");
	game->scene->canvas->instances[0].z = 1;
}