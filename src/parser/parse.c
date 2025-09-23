/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 05:51:33 by yz                #+#    #+#             */
/*   Updated: 2025/09/23 17:22:39 by yz               ###   ########.fr       */
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
	scene->tile = 64.0;
}

/*
** Parses and validates the scene from file descriptor 'fd'.
** Loads scene data, parses, checks, and loads images.
** Returns 0 on success, -1 on error.
*/
int	ft_parse(t_scene *scene, int fd, char *file, t_img *img)
{
	int	len;

	ft_init_scene(scene);
	len = ft_len_file(fd);
	if (len <= 0)
		return (-1);
	ft_read_file(scene, fd, len, file);
	if (ft_parse_file(scene) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	if (ft_scene_check(scene) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	if (ft_load_images(scene, img) == -1)
		return (ft_free_double_pointer(scene->file), -1);
	return (ft_free_double_pointer(scene->file), 0);
}

/*
** Validates command-line arguments and file extension.
** Opens file and returns file descriptor, or error if invalid.
*/
int	ft_arg_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_error(ARG, NULL));
	if (ft_check_ext(av[1], ".cub") == -1)
		return (ft_error(EXT_CUB, NULL));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_error(FD, NULL));
	return (fd);
}
