/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:34:42 by yz                #+#    #+#             */
/*   Updated: 2025/09/26 14:01:22 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_clean_images(t_game *info)
{
	if (info->imgs)
	{
		if (info->imgs->no_text)
			mlx_delete_texture(info->imgs->no_text);
		if (info->imgs->so_text)
			mlx_delete_texture(info->imgs->so_text);
		if (info->imgs->we_text)
			mlx_delete_texture(info->imgs->we_text);
		if (info->imgs->ea_text)
			mlx_delete_texture(info->imgs->ea_text);
	}
}

void	ft_clean_map(t_game	*info)
{
	if (!info)
		return ;
	if (info->scene)
	{
		if (info->scene->map)
			ft_free_double_pointer(info->scene->map);
		if (info->scene->no_path)
			free(info->scene->no_path);
		if (info->scene->so_path)
			free(info->scene->so_path);
		if (info->scene->we_path)
			free(info->scene->we_path);
		if (info->scene->ea_path)
			free(info->scene->ea_path);
		if (info->scene->f_color)
			free(info->scene->f_color);
		if (info->scene->c_color)
			free(info->scene->c_color);
	}
	ft_clean_images(info);
}
