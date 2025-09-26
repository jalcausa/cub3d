/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:45:00 by yz                #+#    #+#             */
/*   Updated: 2025/09/26 14:35:52 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info, char cross)
{
	char	**map;
	int		j;
	int		i;

	map = info->scene->map;
	j = (int)pos.y;
	i = (int)pos.x;
	if (cross == 'x' && ray->sgn.y == -1)
		j--;
	if (cross == 'y' && ray->sgn.x == -1)
		i--;
	if (i >= info->scene->len_x || j >= info->scene->len_y || i < 0 || j < 0)
		return (true);
	if (map[j][i] == '1')
		return (true);
	return (false);
}

double	ft_rayangle(int i, double angle)
{
	int		sine;
	int		cosine;
	double	rayangle;

	sine = (WIDTH / 2) / tan(ft_deg_to_rad(FOV / 2));
	if (i < WIDTH / 2)
	{
		cosine = WIDTH / 2 - i;
		rayangle = angle - atan2(cosine, sine);
	}
	else
	{
		cosine = i - WIDTH / 2;
		rayangle = angle + atan2(cosine, sine);
	}
	if (rayangle < 0)
		rayangle += (M_PI * 2);
	if (rayangle > M_PI * 2)
		rayangle -= (M_PI * 2);
	return (rayangle * 180.0 / M_PI);
}
