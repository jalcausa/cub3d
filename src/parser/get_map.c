/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 10:44:06 by yz                #+#    #+#             */
/*   Updated: 2025/09/22 17:20:19 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*
 * Trims newline characters from a string and pads it with spaces
 * until it reaches the specified max length.
 * Returns the space-padded string.
 */
char	*ft_space_fill(char *str, int max)
{
	int		len;
	char	*spaced;

	spaced = ft_strtrim(str, "\n");
	len = ft_strlen(spaced);
	while (len++ < max)
		spaced = ft_strjoin_sl(spaced, " ");
	return (spaced);
}

/*
 * Creates a new array of strings from arr, starting at 'start',
 * copying 'len' lines and padding each to 'max' length with spaces.
 * Returns the new array or NULL on failure.
 */
char	**ft_get_spaced_map(char **arr, int start, int len, int max)
{
	char	**cpy;
	int		i;

	i = 0;
	if (len > ft_arrlen(arr))
		return (NULL);
	cpy = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	while (arr[start + i] && i < len)
	{
		cpy[i] = ft_space_fill(arr[start + i], max);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
