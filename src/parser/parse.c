/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:51:33 by yz                #+#    #+#             */
/*   Updated: 2025/09/16 11:55:51 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Initialize the essential information about the 3D world with safe default
 * values.
 */
void    ft_init_scene(t_scene *scene)
{
	scene->no_path = NULL;
	scene->so_path = NULL;
	scene->we_path = NULL;
	scene->ea_path = NULL;
	scene->f_color = NULL;
	scene->c_color = NULL;
	scene->file = NULL;
	scene->map = NULL;
	scene->len_x = -1;
	scene->len_y = -1;
}

