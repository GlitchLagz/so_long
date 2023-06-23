/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 01:21:00 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/23 02:06:03 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	ywall(t_vars *g_vars)
{
	int	x;
	int	y;

	x = g_vars->x_max;
	y = 0;
	while (y < g_vars->y_max)
	{
		if (g_vars->map[y][0] != '1' && g_vars->map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	xwall(t_vars *g_vars)
{
	int	x;
	int	k;

	x = g_vars->x_max;
	k = 0;
	while (k < x)
	{
		if (g_vars->map[0][x] == '1' &&
				g_vars->map[g_vars->y_max - 1][k] == '1')
			return (0);
		k++;
	}
	return (1);
}

void	wall_checker(t_vars *g_vars)
{
	int	x_wall;
	int	y_wall;

	y_wall = ywall(g_vars);
	x_wall = xwall(g_vars);
	if (!x_wall || !y_wall)
	{
		write(1, "MAP MISSING WALL", 16);
		g_vars_close(g_vars);
	}
}

void	map_shape(t_vars *g_vars)
{
	int	line_len;
	int	y;

	line_len = g_vars->x_max;
	y = 1;
	while (y < g_vars->y_max)
	{
		if (ft_strlen(g_vars->map[y]) != (size_t)line_len)
		{
			write(1, "MAP NOT RIGHT SHAPE", 19);
			g_vars_close(g_vars);
		}
		y++;
	}
}
