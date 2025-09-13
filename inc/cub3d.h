/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:35:29 by yz                #+#    #+#             */
/*   Updated: 2025/09/13 20:44:00 by jalcausa         ###   ########.fr       */
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
# define WALL_H 500
# define FOV 90

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
	float		tile;
}	t_scene;

typedef struct s_player
{
	mlx_t		*mlx;
	t_coord		pos;		// Cambiar de puntero a valor directo
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
double	ft_deg_to_rad(double deg);
double	ft_get_player_angle(t_scene *scene);
t_coord	ft_get_player_init_pos(t_game *game);
void	ft_init_player(t_player *player, t_game *game);
double	ft_deg_to_rad(double deg);

// raycast.c
t_coord	ft_first_step(t_ray *ray, char cross, double angle, t_game *info);
t_coll	ft_cross_checker(t_ray *ray, t_coord step, t_game *info, char cross);
void	ft_init_ray(t_ray *ray, t_game *info, double angle, t_coord *mod);
t_coll	ft_ray_caster(t_game *info, float angle, t_coord *mod);
double	ft_rayangle(int i, double angle);
bool	ft_coll_checker(t_coord pos, t_ray *ray, t_game *info, char cross);


// paint.c
void	ft_draw_wall(t_game *info, t_coll *coll, int col, int j);
void	ft_draw_col(t_game	*info, float wall, int col, t_coll *coll);

// UTILS
// controls.c
int		ft_collision(t_game *game, double new_x, double new_y);
void	ft_ws(t_player *player, double dir, t_game *game, float angle);
void	ft_ad(t_player *player, double dir, double ang, t_game *game);
void	ft_rotate(t_player *player, double sign, t_game *game);
void	ft_controls(mlx_key_data_t keydata, void *param);

// images.c
void			ft_redisplay(t_game *game);
int				ft_load_images(t_scene *scene, t_img *imgs);
unsigned long	ft_get_pixel_color(mlx_texture_t *txt, int y, int x, int size);
void			ft_draw_pixel(t_game *game);
void			ft_init_pixel(t_coll *coll, int wall, t_game *info);

#endif