/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:42:31 by yz                #+#    #+#             */
/*   Updated: 2025/09/22 17:15:34 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
** Checks if 'str' ends with extension 'ext'.
** Returns 0 if matches, -1 otherwise.
*/
int	ft_check_ext(char *str, char *ext)
{
	int		i;
	char	*tmp;

	if (ft_strchr(str, '.') != 0)
	{
		i = ft_strlen(str);
		while (str[i] != '.')
			i--;
		tmp = &str[i];
		if (!ft_strncmp(tmp, ext, 4))
			return (0);
	}
	return (-1);
}

/*
** Checks that all texture paths in 'scene' end with ".png".
** Returns 0 if valid, -1 if any fail.
*/
static int	ft_texture_check(t_scene *scene)
{
	if (ft_check_ext(scene->no_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->so_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->we_path, ".png") == -1)
		return (-1);
	if (ft_check_ext(scene->ea_path, ".png") == -1)
		return (-1);
	return (0);
}

/*
** Validates the 'scene' structure:
** - Checks texture extensions, floor/ceiling colors, map, and walls.
** Returns 0 if all valid, error otherwise.
*/
int	ft_scene_check(t_scene *scene)
{
	if (ft_texture_check(scene) == -1)
		return (ft_error(EXT_PNG, NULL));
	scene->floor = ft_color_check(scene->f_color);
	scene->ceiling = ft_color_check(scene->c_color);
	if (scene->floor == -1 || scene->ceiling == -1)
		return (ft_error(COLOR, NULL));
	if (ft_char_mapcheck(scene->map) == -1)
		return (-1);
	if (ft_wall_check(scene->map, scene) == -1)
		return (ft_error(WALL, NULL));
	return (0);
}
