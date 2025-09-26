/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:55:01 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/26 14:33:58 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coord	ft_first_step(t_ray *ray, char cross, double angle, t_game *info)
{
	t_coord	pos;
	t_coord	first;

	(void)info;
	if (cross == 'x')
	{
		pos.y = (int)ray->origin.y;
		if (ray->sgn.y == 1)
			pos.y += 1.0;
		first.y = pos.y - ray->origin.y;
		first.x = first.y / tan(angle);
		pos.x = ray->origin.x + first.x;
	}
	if (cross == 'y')
	{
		pos.x = (int)ray->origin.x;
		if (ray->sgn.x == 1)
			pos.x += 1.0;
		first.x = pos.x - ray->origin.x;
		first.y = tan(angle) * first.x;
		pos.y = ray->origin.y + first.y;
	}
	return (pos);
}

t_coll	ft_cross_checker(t_ray *ray, t_coord step, t_game *info, char cross)
{
	t_coord	pos;
	t_coll	coll;

	pos = ft_first_step(ray, cross, ray->angle, info);
	while (1)
	{
		if (ft_coll_checker(pos, ray, info, cross))
		{
			coll.collision.x = pos.x;
			coll.collision.y = pos.y;
			coll.texture = NULL;
			if (cross == 'y')
				coll.txt = 1 * ray->sgn.x;
			else
				coll.txt = 2 * ray->sgn.y;
			break ;
		}
		pos.x += step.x;
		pos.y += step.y;
	}
	coll.raylen = sqrt(pow(pos.x - ray->origin.x, 2)
			+ pow(pos.y - ray->origin.y, 2));
	coll.distance = coll.raylen * cos(ray->deltaang);
	return (coll);
}

void	ft_init_ray(t_ray *ray, t_game *info, double angle, t_coord *mod)
{
	ray->origin.x = info->player->pos.x + mod->x;
	ray->origin.y = info->player->pos.y + mod->y;
	ray->deltaang = ft_deg_to_rad(info->player->angle) - angle;
	ray->angle = angle;
	ray->dir.x = cos(angle);
	ray->dir.y = sin(angle);
	ray->sgn.x = 1;
	ray->sgn.y = 1;
	if (ray->dir.x < 0)
		ray->sgn.x *= -1;
	if (ray->dir.y < 0)
		ray->sgn.y *= -1;
	ray->x_cross.x = ray->sgn.y / tan(angle);
	ray->x_cross.y = ray->sgn.y;
	ray->y_cross.x = ray->sgn.x;
	ray->y_cross.y = tan(angle) * ray->sgn.x;
}

t_coll	ft_ray_caster(t_game *info, float angle, t_coord *mod)
{
	t_coll	x_coll;
	t_coll	y_coll;
	t_ray	ray;

	ft_init_ray(&ray, info, ft_deg_to_rad(angle), mod);
	x_coll = ft_cross_checker(&ray, ray.x_cross, info, 'x');
	y_coll = ft_cross_checker(&ray, ray.y_cross, info, 'y');
	if (x_coll.raylen < y_coll.raylen)
		return (x_coll);
	else
		return (y_coll);
}
