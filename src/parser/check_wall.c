/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:43:08 by yz                #+#    #+#             */
/*   Updated: 2025/09/22 17:21:22 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
 * Checks if the given position (x, y) in the map is incorrectly exposed.
 * Returns 1 if the position is on the edge or next to an empty space,
 * indicating a wall should be present; otherwise returns 0.
 */
int	ft_is_wall(char **map, int x, int y, t_scene *scene)
{
	if (y == 0 && map[y][x] > 32)
		return (1);
	if (y == scene->len_y - 1 && map[y][x] > 32)
		return (1);
	if (x == 0 && map[y][x] > 32)
		return (1);
	if (x == scene->len_x - 1 && map[y][x] > 32)
		return (1);
	if (y > 0 && map[y - 1][x] <= 32)
		return (1);
	if (y < scene->len_y - 1 && map[y + 1][x] <= 32)
		return (1);
	if (x > 0 && map[y][x - 1] <= 32)
		return (1);
	if (x < scene->len_x - 1 && map[y][x + 1] <= 32)
		return (1);
	return (0);
}

/*
 * Iterates through the map to verify that all non-space positions
 * are properly surrounded by walls ('1'). Returns -1 if a leak is
 * detected (open map), otherwise returns 1 if the map is properly enclosed.
 */
int	ft_wall_check(char **map, t_scene *scene)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] && y < scene->len_y)
	{
		x = 0;
		while (map[y][x] && x < scene->len_x)
		{
			while (map[y][x] > 0 && map[y][x] <= 32)
				x++;
			if (map[y][x] != 0 && ft_is_wall(map, x, y, scene) \
			&& map[y][x] != '1')
				return (-1);
			x++;
		}
		y++;
	}
	return (1);
}
