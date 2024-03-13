/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hbelle <hbelle@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/11 16:47:27 by hbelle            #+#    #+#             */
/*   Updated: 2024/03/11 16:47:27 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <../minilibx-linux/mlx.h>
# include <../libft/libft.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map_array;
	char	**map_array_copy;
	int		map_size_y;
	int		map_size_x;
	int		map_position;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_c[3];
	int		ceiling_c[3];
	int		player_direction[4];
	int		player_position[2];
}	t_map;

// PARSES

void	ft_acces_texture(t_map *cube, char *line, int i);
void	ft_check_wall(t_map *cube, int x, int y);
void	ft_find_player_position(t_map *cube);
void	ft_check_args(int ac);
void	ft_check_map_file(t_map *cube, char *map);
int		ft_check_texture(t_map *cube, char *line);
void	ft_check_map_content(t_map *cube, int fd);

// UTILS

void	ft_init(t_map *cube);
void	ft_error_handle(t_map *cube, char *error, char *str, int status);
void	ft_error_handle_color(t_map *cube, char *line);
void	ft_skip_spaces(char *line, int *i, int *count);
void	cut_extra_char(char *str);
void	ft_fill_line(char *line, int size);

// DATA

void	ft_cp_array(t_map *cube);
void	ft_map_into_array(t_map *cube, char *map);

#endif