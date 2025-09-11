/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:35:29 by yz                #+#    #+#             */
/*   Updated: 2025/09/11 19:48:44 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <unistd.h>    // open, close, read, write
#include <fcntl.h>     // open
#include <stdio.h>     // printf, perror
#include <stdlib.h>    // malloc, free, exit
#include <string.h>    // strerror
#include <sys/time.h>  // gettimeofday
#include <math.h>      // math functions
#include <limits.h>    // INT_MAX
#include <stdbool.h>   // bool, true, false
# include "../libft/libft.h" // libft
#include "../MLX42/include/MLX42/MLX42.h"       // MiniLibX

# define WIDTH 1080
# define HEIGHT 720

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_img
{
	mlx_texture_t		*no_text;
	mlx_texture_t		*so_text;
	mlx_texture_t		*we_text;
	mlx_texture_t		*ea_text;
	int					size;
	long unsigned int	color_pix;
}	t_img;

typedef struct s_scene
{
	char		**file;
	char		**map;
	char		*no_path;
	char		*so_path;
	char		*we_path;
	char		*ea_path;
	char		*f_color;
	char		*c_color;
	int			floor;
	int			ceiling;
	int			counter;
	int			len_x;
	int			len_y;
	mlx_image_t	*canvas;
}	t_scene;

typedef struct s_player
{
	mlx_t		*mlx;
	t_coord		*pos;
	double		mov_speed;
	double		rot_speed;
	int			angle;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	deltaang;
	t_coord	origin;
	t_coord	dir;
	t_coord	x_cross;
	t_coord	y_cross;
	t_coord	sgn;
	t_coord	coll;
	double	len;
}	t_ray;

typedef struct s_coll
{
	t_coord			collision;
	double			raylen;
	double			distance;
	int				txt;
	mlx_texture_t	*texture;
	t_coord			pixel;
	int				wall;
	float			ratio;
}	t_coll;

typedef struct s_game
{
	mlx_t		*mlx;
	t_scene		*scene;
	t_img		*imgs;
	t_player	*player;
	t_ray		*ray;
}	t_game;

typedef enum e_errors
{
	ARG = 1,
	EXT_CUB,
	FD,
	FORMAT,
	WALL,
	CHAR,
	EMPTY,
	PLAYER,
	EXT_PNG,
	COLOR,
	WINDOW,
	IMAGE,
}		t_errors;

// RENDER
// player.c
double	ft_get_player_angle(t_scene *scene);
t_coord	ft_get_player_init_pos(t_game *game);
void	ft_init_player(t_player *player, t_game *game);

#endif