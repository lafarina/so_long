/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laufarin <laufarin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:48:28 by laufarin          #+#    #+#             */
/*   Updated: 2024/06/22 18:55:17 by laufarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct s_images
{
	char	*img_p;
	int		bpp;
	int		len_p;
	int		endian;
	void	*collect;
	void	*empty;
	void	*exit;
	void	*player;
	void	*wall;
	void	*winner;
	int		img_width;
	int		img_heigth;
	int		i;
	int		j;
}	t_images;

typedef struct s_checker
{
	char	**map_cpy;
	int		collect_left;
}	t_checker;

typedef struct s_map_data
{
	void		*mlx;
	void		*window;
	char		**map;
	int			height;
	int			width;
	int			x;
	int			y;
	int			player;
	int			n_collect;
	int			n_moves;
	int			fd;
	char		*big_str;
	void		*right;
	void		*left;
	void		*down;
	void		*up;
	void		*img;
	t_images	*images;
}	t_map_data;

// CHECKER_MAPS //

int			map_is_rect(t_map_data *info);
int			map_is_close(t_map_data *info);
int			map_size_max(t_map_data *info);
int			map_correct_char(char **map);
int			map_correct_objects(t_map_data *info);
void		check_fill_map(t_checker *c, t_map_data *info, int i, int j);
t_checker	*cpy_map(t_checker *c, t_map_data *info);

//CHEC_FILE

int			is_ber(char *str);
void		get_map(char *path, t_map_data *info);

//WINDOW_HANDLING

void	configure_images(t_map_data *info, t_images *img);
void    setup_game(t_map_data *info, t_images *img);

//MAIN

int			general_checker_maps(t_map_data *info);

//UTILS

char	*free_map(char **map);
int		error_exit(t_map_data *info);
void	*safe_malloc(size_t size);

#endif
