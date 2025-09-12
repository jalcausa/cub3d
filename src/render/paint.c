/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:58:51 by jalcausa          #+#    #+#             */
/*   Updated: 2025/09/12 14:08:22 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_wall(t_game *info, t_coll *coll, int col, int j)
{
	unsigned long	color;

	// Diferentes colores según la orientación de la pared
	if (coll->txt == 1)
		color = 0xFF0000FF;      // Rojo - Este
	else if (coll->txt == -1) 
		color = 0x00FF00FF;      // Verde - Oeste
	else if (coll->txt == 2)
		color = 0x0000FFFF;      // Azul - Sur  
	else if (coll->txt == -2)
		color = 0xFFFF00FF;      // Amarillo - Norte
	else
		color = 0x8B4513FF;      // Marrón por defecto

	while (j < HEIGHT / 2 + coll->wall / 2)
	{
		if (j < 0 || j > HEIGHT)
			break ;
		mlx_put_pixel(info->scene->canvas, col, j, color);
		j++;
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
		
	// Asignar altura de pared a la estructura coll para ft_draw_wall
	coll->wall = wall;
	
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
