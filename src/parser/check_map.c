/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:41:56 by yz                #+#    #+#             */
/*   Updated: 2025/09/22 17:15:37 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
** Checks if the character is valid for the map:
** - Returns 1 for '0', '1', or control characters.
** - Returns 42 for 'N', 'S', 'E', 'W'.
** - Returns 0 otherwise.
*/
int	ft_char_check(char c)
{
	int	ret;

	ret = 0;
	if (c > 0 && c < 33)
		ret = 1;
	if (c == '0' || c == '1')
		ret = 1;
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ret = 42;
	return (ret);
}

/*
** Checks the entire map:
** - Validates each character.
** - Ensures exactly one player start position.
** - Returns 0 if valid, error if not.
*/
int	ft_char_mapcheck(char **map)
{
	int	i;
	int	j;
	int	ret;
	int	count;

	j = -1;
	ret = 0;
	count = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			ret = ft_char_check(map[j][i]);
			if (!ret)
				return (ft_error(CHAR, NULL));
			if (ret == 42)
				count++;
		}
	}
	if (count != 1)
		return (ft_error(PLAYER, NULL));
	return (0);
}
