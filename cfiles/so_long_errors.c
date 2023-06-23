/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:48:21 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/23 02:04:23 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static void	counter_checkerpt2(t_vars *g_vars, int y, int x)
{
	if (g_vars->map[y][x] != 'P' &&
			g_vars->map[y][x] != 'E' &&
			g_vars->map[y][x] != 'C' &&
			g_vars->map[y][x] != '1' &&
			g_vars->map[y][x] != '0' &&
			g_vars->map[y][x] != '\n' &&
			g_vars->map[y][x] != '\0')
	{
		write(1, "UNRECOGNISED CHAR", 17);
		g_vars_close(g_vars);
	}
	if (g_vars->map[y][x] == 'C')
		g_vars->collectc++;
	if (g_vars->map[y][x] == 'E')
	{
		g_vars->exitc++;
		g_vars->ex = x;
		g_vars->ey = y;
	}
	if (g_vars->map[y][x] == 'P')
	{
		g_vars->playerc++;
		g_vars->xpos = x;
		g_vars->ypos = y;
	}
}

void	counter_checker(t_vars *g_vars)
{
	int	x;
	int	y;

	y = 1;
	while (y < g_vars->y_max - 1)
	{
		x = 1;
		while (x <= g_vars->x_max)
			counter_checkerpt2(g_vars, y, x++);
		y++;
	}
	if ((g_vars->playerc != 1) || (g_vars->exitc != 1)
		|| (g_vars->collectc < 1))
	{
		write(1, "WRONG GAME VARS", 15);
		g_vars_close(g_vars);
	}
}

void	path_checker(char **copy, int y_tar, int x_tar, t_vars g_vars)
{
	int	y;
	int	x;

	y = 1;
	while (y < g_vars.y_max)
	{
		x = 1;
		while (x < g_vars.x_max)
		{
			if (x == x_tar && y == y_tar)
			{
				copy[y][x] = 'F';
				up(copy, y, x, g_vars);
				down(copy, y, x, g_vars);
				left(copy, y, x, g_vars);
				right(copy, y, x, g_vars);
			}
			x++;
		}
		y++;
	}
}

int	err_check(int nb, t_vars *g_vars)
{
	if (nb == 1)
	{
		perror("WRONG ARGUMENTS: ");
		exit(1);
	}
	if (nb == 2)
	{
		perror("MAP READ ERR: ");
		exit(1);
	}
	if (nb == 0)
	{
		map_shape(g_vars);
		wall_checker(g_vars);
		counter_checker(g_vars);
	}
	return (nb);
}
