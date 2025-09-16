/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:58:51 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/13 20:04:47 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_wall(t_game *info, t_coll *coll, int col, int j)
{
	unsigned long	color;
	float			y;
	int				x;

	y = coll->pixel.y;
	x = (int)coll->pixel.x;
	while ((uint32_t)y < coll->texture->height && j < HEIGHT / 2 + coll->wall / 2)
	{
		color = \
		ft_get_pixel_color(coll->texture, (int)y, x, coll->texture->width);
		if (j < 0 || j > HEIGHT)
			break ;
		mlx_put_pixel(info->scene->canvas, col, j, color);
		j++;
		y += coll->ratio;
	}
}

void	ft_draw_col(t_game	*info, float wall, int col, t_coll *coll)
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
		
	// Inicializar pixel data para texturas
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
