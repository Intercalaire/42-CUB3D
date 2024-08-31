/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:41:36 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/28 14:42:34 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"

# define WALL_HEIGHT 1
# define VIEW_HEIGHT 0.5
# define SCREEN 1
# define ROT_SPEED 0.08
# define MOVE_SPEED 0.02
# define HEIGHT 720
# define WIDTH 1280
# define MAX 1e30


typedef struct textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
	mlx_texture_t	*tmp_player_on_map;
}					t_textures;

typedef struct vars
{
	int					floor[3];
	int					ceiling[3];
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				**map;


	double				dirX; // Vise le bloc devant le player afin d'avoir la dir
	double				dirY; // dirX and dirY represent the direction of the player
	double				planeX;
	double				planeY; // planeX and planeY the camera plane of the player
	double				rayDirX;
	double				rayDirY;
	double				sideDistX; //longueur du rayon d'un côté x ou y au côté x ou y suivant
	double				sideDistY;
	double				deltaDistX;
	double				deltaDistY;
	double				stepX;
	double				stepY;
	double				cameraX; // idem
	double				cameraY; // Maybe useless
	double				posX;
	double				posY; // posX and posY represent the position vector of the player



	double				time; //time of current frame // Maybe sa degage
	double				oldTime; //time of previous frame // Maybe sa degage



	int					player_pos[2]; // Maybe == posX/Y
	int32_t				mouse_pos[2];

	mlx_image_t			*tmp;

	mlx_t				*window;
	mlx_image_t			*player_on_map;
	mlx_image_t			*mini_map;
	mlx_win_cursor_t	*cursor;
	t_textures			*textures;
}				t_vars;

/*
* Main
*/

void	init(t_vars *vars, char *str);

/*
* Parsing
*/

void	parse_file(char *file);
void	check_data(char **file);
void	check_map(char **map);
int		check_closed_map(char **map);
int		check_player_char(char **map);

/*
* Utils
*/

int		ft_strlen(const char *str);
int		len_db_char(char **str);
int		ft_strcspn(const char *s, char *reject);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *str);
int		ft_isalpha(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_putstr_fd(char *s, int fd);
char	**get_file(int fd);
char	**ft_split(char const *s, char c);
int		skip_space(char *str);
int		invert_skip_space(char *str);
char	**get_map(char **file);
int		start_map(char **file);
char	*copy(char *s);
void	get_borders(char *tab, char *line, int i);
int		verif_map_split(char *s);
int		is_parameter(char *s);
void	ft_free_vars(t_vars *vars);
void	ft_free(char **str);

/*
* Errors
*/

void	nb_arg_error(void);
void	empty_arg(void);
void	error_fd(void);
void	error_malloc(int fd, char **tab);
void	error_read(int fd, char *buffer, char *getter);
void	map_error(void);

#endif