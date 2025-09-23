/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:42:07 by yz                #+#    #+#             */
/*   Updated: 2025/09/23 12:01:36 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
** Counts occurrences of character 'c' in the string 'str'.
** Returns the count.
*/
static int	ft_char_counter(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

/*
** Converts string 'str' to int.
** Returns -1 if negative or invalid input.
*/
static int	ph_atoi(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (str[i] != 0)
		return (-1);
	return (num);
}

/**
 * r << 24 = 0x78 << 24 = 0x78000000
 * g << 16 = 0xC8 << 16 = 0x00C80000
 * b << 8 = 0x32 << 8 = 0x00003200
 * 0xFF = 0x000000FF
 */
int	ft_rgb_to_hex(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 0xFF);
}

/**
 * Checks if the rgb values are valid
 */
int	ft_get_colour(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ph_atoi(rgb[0]);
	g = ph_atoi(rgb[1]);
	b = ph_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255
		|| b < 0 || b > 255)
		return (-1);
	return (ft_rgb_to_hex(r, g, b));
}

/*
** Validates and converts color string to hex.
** Returns -1 if format or values are invalid.
*/
int	ft_color_check(char *color)
{
	int		ret;
	char	**rgb;

	ret = 0;

	if (ft_char_counter(color, ',') > 2)
		return (-1);
	rgb = ft_old_split(color, ',');
	if (ft_arrlen(rgb) != 3)
		ret = -1;
	else
		ret = ft_get_colour(rgb);
	ft_free_double_pointer(rgb);
	return (ret);
}
