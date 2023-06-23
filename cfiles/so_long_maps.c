/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:53:10 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/22 22:38:24 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	*ft_mapinit(void *b, int p, size_t len)
{
	unsigned char	*ptr;
	int				i;

	i = 0;
	ptr = (unsigned char *)b;
	while (len--)
		ptr[i++] = (unsigned char)p;
	return (b);
}

int	ft_mapline(char	*line, t_vars *g_vars, int y_len)
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
		tmp[i] = g_vars->map[i];
		i++;
	}
	if (g_vars->map)
		free(g_vars->map);
	tmp[i] = line;
	g_vars->map = tmp;
	return (1);
}

int	ft_map_vars(char **argv, t_vars *g_vars)
{
	int		fd;
	int		y_len;
	int		x_len;
	char	*res;

	y_len = 0;
	x_len = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	while (1)
	{
		res = get_next_line(fd);
		if (res != NULL)
			y_len++;
		if (!ft_mapline(res, g_vars, y_len))
			break ;
		x_len = ft_strlen(res);
	}
	close(fd);
	g_vars->y_max = y_len;
	g_vars->x_max = x_len;
	return (1);
}
