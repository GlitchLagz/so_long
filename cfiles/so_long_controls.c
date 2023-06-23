/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 23:51:24 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/14 18:14:37 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	s(int cmd, t_vars *g_vars)
{
	int	x;
	int	y;
	int	l;

	x = g_vars->xpos;
	y = g_vars->ypos;
	if (cmd == 1)
	{
		y++;
		if (g_vars->map[y][x] == '1')
			return (0);
		l = legal_move(g_vars, x, y);
		if (!l)
			return (0);
		g_vars->map[y - 1][x] = '0';
	}
	ft_printf("Moves Made: %d\n", g_vars->movec);
	ft_printf("Collectables Remaining: %d\n", g_vars->collectc);
	return (1);
}

static int	w(int cmd, t_vars *g_vars)
{	
	int	x;
	int	y;
	int	l;

	x = g_vars->xpos;
	y = g_vars->ypos;
	if (cmd == 13)
	{
		y--;
		if (g_vars->map[y][x] == '1')
			return (0);
		l = legal_move(g_vars, x, y);
		if (!l)
			return (0);
		g_vars->map[y + 1][x] = '0';
	}
	ft_printf("Moves Made: %d\n", g_vars->movec);
	ft_printf("Collectables Remaining: %d\n", g_vars->collectc);
	return (1);
}

static int	a(int cmd, t_vars *g_vars)
{
	int	x;
	int	y;
	int	l;

	x = g_vars->xpos;
	y = g_vars->ypos;
	if (cmd == 0)
	{
		x--;
		if (g_vars->map[y][x] == '1')
			return (0);
		l = legal_move(g_vars, x, y);
		if (!l)
			return (0);
		g_vars->map[y][x + 1] = '0';
	}
	ft_printf("Moves Made: %d\n", g_vars->movec);
	ft_printf("Collectables Remaining: %d\n", g_vars->collectc);
	return (1);
}

static int	d(int cmd, t_vars *g_vars)
{
	int	x;
	int	y;
	int	l;

	x = g_vars->xpos;
	y = g_vars->ypos;
	if (cmd == 2)
	{
		x++;
		if (g_vars->map[y][x] == '1')
			return (0);
		l = legal_move(g_vars, x, y);
		if (!l)
			return (0);
		g_vars->map[y][x - 1] = '0';
	}
	ft_printf("Moves Made: %d\n", g_vars->movec);
	ft_printf("Collectables Remaining: %d\n", g_vars->collectc);
	return (1);
}

int	live_ctrls(int cmd, t_vars *g_vars)
{
	int	re_render;

	re_render = 0;
	if (cmd == 53)
		g_vars_close(g_vars);
	if (cmd == 13 || cmd == 0 || cmd == 2 || cmd == 1)
	{
		if (cmd == 13)
			re_render = w(cmd, g_vars);
		if (cmd == 1)
			re_render = s(cmd, g_vars);
		if (cmd == 0)
			re_render = a(cmd, g_vars);
		if (cmd == 2)
			re_render = d(cmd, g_vars);
	}
	if (re_render == 1)
		match_sprites(g_vars);
	return (1);
}
