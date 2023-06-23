/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 07:38:28 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/23 00:04:26 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef OPEN_LIMIT
#  define OPEN_LIMIT 254
# endif

typedef struct s_vars {
	int		xpos;
	int		ypos;
	int		collectc;
	int		playerc;
	int		exitc;
	int		movec;
	int		x_max;
	int		y_max;
	int		ey;
	int		ex;
	int		copycollectc;
	int		copyexitc;
	char	**map;
	char	**copy;
	void	*player;
	void	*wall;
	void	*tile;
	void	*collectable;
	void	*exit;
	void	*mlx;
	void	*window;
}			t_vars;

int			ft_mapline(char *line, t_vars *g_vars, int ylen);
void		count_checker(t_vars *g_vars);
void		wall_checker(t_vars *g_vars);
void		match_sprites(t_vars *g_vars);
void		match_image(int nb, t_vars *g_vars, int y, int x);
void		render_sprites(t_vars *g_vars);
void		*ft_mapinit(void *b, int p, size_t len);
void		path_checker(char **copy, int y_tar, int x_tar, t_vars g_vars);
void		up(char **map, int y, int x, t_vars g_vars);
void		down(char **map, int y, int x, t_vars g_vars);
void		left(char **map, int y, int x, t_vars g_vars);
void		right(char **map, int y, int x, t_vars g_vars);
void		map_shape(t_vars *g_vars);
int			ft_copy(char **argv, t_vars *g_vars);
int			legal_move(t_vars *g_vars, int x, int y);
int			live_ctrls(int cmd, t_vars *g_vars);
int			g_vars_close(t_vars *g_vars);
int			ft_map_vars(char **argv, t_vars *g_vars);
int			err_check(int nb, t_vars *g_vars);
int			main(int argc, char **argv);

/* get next line functions */
char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
