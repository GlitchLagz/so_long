/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:01:43 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/23 00:02:27 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	up(char **map, int y, int x, t_vars g_vars)
{
	if ((y - 1) >= 0 && (map[(y - 1)][x] == '0'
		|| map[(y - 1)][x] == 'C'
		|| map[(y - 1)][x] == 'E'))
	{
		path_checker(map, y - 1, x, g_vars);
	}
}

void	down(char **map, int y, int x, t_vars g_vars)
{
	if ((y + 1) < g_vars.y_max && (map[(y + 1)][x] == '0'
		|| map[(y + 1)][x] == 'C'
		|| map[(y + 1)][x] == 'E'))
	{
		path_checker(map, y + 1, x, g_vars);
	}
}

void	left(char **map, int y, int x, t_vars g_vars)
{
	if ((x - 1) > 0 && (map[y][(x - 1)] == '0'
		|| map[y][x - 1] == 'C'
		|| map[y][x - 1] == 'E'))
	{
		path_checker(map, y, x - 1, g_vars);
	}
}

void	right(char **map, int y, int x, t_vars g_vars)
{
	if ((x + 1) < g_vars.x_max && (map[y][(x + 1)] == '0'
		|| map[y][x + 1] == 'C'
		|| map[y][x + 1] == 'E'))
	{
		path_checker(map, y, x + 1, g_vars);
	}
}
