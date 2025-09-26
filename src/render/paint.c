/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:58:51 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/26 14:25:53 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_wall_end(int wall)
{
	int	end;

	end = HEIGHT / 2 + wall / 2;
	if (end > HEIGHT)
		end = HEIGHT;
	return (end);
}

void	ft_draw_wall(t_game *info, t_coll *coll, int col, int j)
{
	unsigned long	color;
	float			y;
	int				x;
	int				end;

	y = coll->pixel.y;
	x = (int)coll->pixel.x;
	end = ft_get_wall_end(coll->wall);
	if (j < 0)
		j = 0;
	while ((uint32_t)y < coll->texture->height && j < end)
	{
		color = ft_get_pixel_color(coll->texture, (int)y, x,
				coll->texture->width);
		if (col < 0 || col >= WIDTH)
			break ;
		if (j < 0 || j >= HEIGHT)
			break ;
		mlx_put_pixel(info->scene->canvas, col, j, color);
		j++;
		y += coll->ratio;
	}
}

void	ft_draw_col(t_game *info, float wall, int col, t_coll *coll)
{
	int	j;
	int	top;
	int	bot;

	top = HEIGHT / 2 - wall / 2;
	if (top < 0)
		top = 0;
	bot = top + wall;
	if (bot > HEIGHT)
		bot = HEIGHT;
	ft_init_pixel(coll, wall, info);
	j = 0;
	while (j < HEIGHT)
	{
		if (j < top)
			mlx_put_pixel(info->scene->canvas, col, j, info->scene->ceiling);
		else if (j > bot)
			mlx_put_pixel(info->scene->canvas, col, j, info->scene->floor);
		j++;
	}
	ft_draw_wall(info, coll, col, top);
}
