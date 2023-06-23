/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_controls2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:29:33 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/14 17:52:12 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	legal_move(t_vars *g_vars, int x, int y)
{
	if (g_vars->map[y][x] == 'E')
	{
		if (g_vars->collectc != 0)
			return (0);
		ft_printf("You Beat So_Long!\n");
		g_vars_close(g_vars);
	}
	if (g_vars->map[y][x] == '0')
	{
		g_vars->map[y][x] = 'P';
		g_vars->xpos = x;
		g_vars->ypos = y;
		g_vars->movec++;
	}
	if (g_vars->map[y][x] == 'C')
	{
		g_vars->map[y][x] = 'P';
		g_vars->xpos = x;
		g_vars->ypos = y;
		g_vars->collectc--;
		g_vars->movec++;
	}
	return (1);
}
