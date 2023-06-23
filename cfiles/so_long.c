/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:38:05 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/23 00:00:35 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	g_vars_close(t_vars *g_vars)
{
	int	tmp;

	tmp = 0;
	if (g_vars->window)
		mlx_destroy_window(g_vars->mlx, g_vars->window);
	free(g_vars->mlx);
	while (tmp < g_vars->y_max -1)
		free(g_vars->map[tmp++]);
	free(g_vars->map);
	exit(0);
}

static int	ft_maplinecopy(char *line, t_vars *g_vars, int y_len)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!line)
		return (0);
	tmp = (char **)malloc(sizeof(char *) * (y_len + 1));
	tmp[y_len] = NULL;
	while (i < y_len - 1)
	{
		tmp[i] = g_vars->copy[i];
		i++;
	}
	if (g_vars->copy)
		free(g_vars->copy);
	tmp[i] = line;
	g_vars->copy = tmp;
	return (1);
}

int	ft_copy(char **argv, t_vars *g_vars)
{
	int		fd;
	char	*res;
	int		y_len;

	y_len = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		res = get_next_line(fd);
		if (res != NULL)
			y_len++;
		if (!ft_maplinecopy(res, g_vars, y_len))
			break ;
	}
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	g_vars;

	if (argc != 2)
		err_check(1, &g_vars);
	ft_mapinit(&g_vars, 0, sizeof(g_vars));
	if (ft_map_vars(argv, &g_vars) != 1)
		err_check(2, &g_vars);
	if (!ft_copy(argv, &g_vars))
		err_check(2, &g_vars);
	err_check(0, &g_vars);
	path_checker(g_vars.copy, g_vars.ypos, g_vars.xpos, g_vars);
	if (g_vars.copy[g_vars.ey][g_vars.ex] != 'F')
	{
		write(1, "NO PATH", 7);
		g_vars_close(&g_vars);
	}
	g_vars.mlx = mlx_init();
	g_vars.window = mlx_new_window(g_vars.mlx, g_vars.x_max * 100,
			g_vars.y_max * 100, "so_long");
	render_sprites(&g_vars);
	match_sprites(&g_vars);
	mlx_key_hook(g_vars.window, live_ctrls, &g_vars);
	mlx_hook(g_vars.window, 17, 0, g_vars_close, &g_vars);
	mlx_loop(g_vars.mlx);
}
