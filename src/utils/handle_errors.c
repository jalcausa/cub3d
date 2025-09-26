/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yz <yz@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 09:26:32 by yz                #+#    #+#             */
/*   Updated: 2025/09/26 14:02:59 by yz               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * Helper function to print instructions in case of invalid file format
 */
static void	ft_print_fileformat(char *str)
{
	printf("%s\n", WRONG);
	printf("========== FILE FORMAT ERROR ==========\n");
	printf("%sIncorrect file format detected!%s\n", WRONG, END);
	if (*str)
		printf("%sDetails: %s%s\n", WRONG, str, END);
	printf("---------------------------------------\n");
	printf("Your .cub file must include:\n");
	printf("  - Wall textures: NO, SO, WE, EA\n");
	printf("  - Colors: F (floor), C (ceiling)\n");
	printf("    (any order, one per line)\n");
	printf("\nMap section must come last and only contain:\n");
	printf("  - 0 (empty), 1 (wall), N/S/E/W (player start)\n");
	printf("\nExample:\n");
	printf("  NO ./textures/north.png\n");
	printf("  SO ./textures/south.png\n");
	printf("  WE ./textures/west.png\n");
	printf("  EA ./textures/east.png\n");
	printf("  F 200,100,0\n");
	printf("  C 100,100,100\n");
	printf("\n  111111\n");
	printf("  100001\n");
	printf("  1010N1\n");
	printf("  100001\n");
	printf("  111111\n");
	printf("%s", END);
}

void	ft_parse_errors(int err, char *str)
{
	if (err == ARG)
		printf("%sError\nWrong input%s\n", WRONG, END);
	if (err == EXT_CUB)
		printf("%sError\nThe map file doesn't have "
			"a valid extension. It must be .cub%s\n", WRONG, END);
	if (err == EXT_PNG)
		printf("%sError\nThe texture file doesn't have "
			"a valid extension. It must be .png%s\n", WRONG, END);
	if (err == FD)
		printf("%sError\nProblem while opening file%s\n", WRONG, END);
	if (err == FORMAT)
		ft_print_fileformat(str);
	if (err == WALL)
		printf("%sError\nThe map must be surrounded by walls%s\n", WRONG, END);
	if (err == CHAR)
		printf("%sError\nThe map contains invalid characters%s\n", WRONG, END);
	if (err == EMPTY)
		printf("%sError\nInvalid file, empty map%s\n", WRONG, END);
	if (err == PLAYER)
		printf("%sError\nThe map must have one player"
			"position%s\n", WRONG, END);
	if (err == COLOR)
		printf("%sError\nIncorrect colour format%s\n", WRONG, END);
}

void	ft_mlx_errors(int err, char *str)
{
	if (err == WINDOW)
		printf("%sError while opening the window\n%s%s\n", WRONG, str, END);
	if (err == IMAGE)
		printf("%sError while rendering an image\n%s%s\n", WRONG, str, END);
}

/**
 * Handle and report errors in a consistent way.
 * 
 * 1- Identify Error Type
 * 2- Displays the Error Message
 *
 */
int	ft_error(int err, char *str)
{
	if (err == 42)
		printf("%sError\n%s%s\n", WRONG, str, END);
	ft_parse_errors(err, str);
	ft_mlx_errors(err, str);
	return (-1);
}
