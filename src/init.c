/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:20:49 by yz                #+#    #+#             */
/*   Updated: 2025/09/26 14:22:43 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_game(t_game *info)
{
	ft_init_player(info->player, info);
	mlx_key_hook(info->mlx, &ft_controls, info);
	mlx_loop_hook(info->mlx, &ft_loop_handler, info);
	mlx_loop(info->mlx);
}

void	ft_init_structs(t_game *info, t_img *imgs)
{
	info->scene = NULL;
	info->player = NULL;
	info->imgs = NULL;
	info->mlx = NULL;
	imgs->no_text = NULL;
	imgs->so_text = NULL;
	imgs->we_text = NULL;
	imgs->ea_text = NULL;
}
