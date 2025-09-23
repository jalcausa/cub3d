/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:16:52 by yz                #+#    #+#             */
/*   Updated: 2025/09/23 17:18:04 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

/*This function serves to free the buffer of the previously read line, and keep
only what could be stored of the next one, in order to later store that remainder
in the static variable (here 'leftover') when it goes through get_next_line.*/

char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	leftover = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (buffer[i] != '\0')
	{
		leftover[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	return (leftover);
}

/*This function replicates the functionality of read(), as it takes the value
of BUFFER_SIZE to read the same amount of bytes.

In addition, it is the one that concatenates the read lines, because we can not
read the entire file at once. Therefore, we will be returning line by line and 
maintaining the position of the 'cursor' thanks to the static variable.*/

char	*ft_read_line(int fd, char *buffer)
{
	char	*tmp;
	int		n;

	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	n = 1;
	while (n != 0 && !ft_strchr(buffer, '\n'))
	{
		n = read(fd, tmp, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[n] = '\0';
		buffer = ft_strjoin_sl(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

/*This function actually doesn't do much, because the different actions are
performed by the other three, but it gives execution order and adds some error
checks.*/

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
