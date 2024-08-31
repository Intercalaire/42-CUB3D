/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 07:15:58 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/28 11:00:59 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	get_colors(char *str, t_vars *vars)
{
	int		i;
	int		j;
	char	**rgb;

	j = 0;
	rgb = NULL;
	i = skip_space(str);
	if (str[i] == 'C'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		i++;
		i = skip_space(&str[i]);
		rgb = ft_split(&str[i], ',');
		while (rgb && rgb[j])
		{
			vars->ceiling[j] = ft_atoi((char *)rgb[j]);
			j++;
		}
	}
	if (str[i] == 'F'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		i++;
		i = skip_space(&str[i]);
		rgb = ft_split(&str[i], ',');
		while (rgb && rgb[j])
		{
			vars->floor[j] = ft_atoi((char *)rgb[j]);
			j++;
		}
	}
	if (!rgb && str[i] != '\0'
		&& (str[skip_space(str)] == 'C' || str[skip_space(str)] == 'F'))
	{
		ft_putstr_fd("Error\nAn error occured while getting colors! ❌\n", 2);
		ft_free_vars(vars);
		error_malloc(-1, NULL);
	}
	ft_free(rgb);
}

static void	get_textures(char *str, t_vars *vars)
{
	int	i;
	int	tmp;

	i = skip_space(str);
	if (str[i] == 'N' && str[i + 1] == 'O'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		tmp = skip_space(&str[i + 2]);
		i = tmp + 2;
		vars->north = copy(&str[i]);
	}
	if (str[i] == 'S' && str[i + 1] == 'O'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		tmp = skip_space(&str[i + 2]);
		i = tmp + 2;
		vars->south = copy(&str[i]);
	}
	if (str[i] == 'E' && str[i + 1] == 'A'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		tmp = skip_space(&str[i + 2]);
		i = tmp + 2;
		vars->east = copy(&str[i]);
	}
	if (str[i] == 'W' && str[i + 1] == 'E'
		&& (str[i + 2] == ' ' || str[i + 2] == '\t'))
	{
		tmp = skip_space(&str[i + 2]);
		i = tmp + 2;
		vars->west = copy(&str[i]);
	}
}

static void	get_parameters(t_vars *vars, char **file)
{
	int	i;

	i = 0;
	while (file && file[i])
	{
		get_textures(file[i], vars);
		get_colors(file[i], vars);
		i++;
	}
	if (!vars->north || !vars->south || !vars->east || !vars->west)
	{
		ft_putstr_fd("Error\nAn error occured while getting textures! ❌\n", 2);
		ft_free_vars(vars);
	}
}

void	get_directions(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == 'N')
	{
		vars->dirX = i - 1;
		vars->dirY = j;
	}
	else if (vars->map[i][j] == 'S')
	{
		vars->dirX = i + 1;
		vars->dirY = j;
	}
	else if (vars->map[i][j] == 'E')
	{
		vars->dirX = i;
		vars->dirY = j + 1;
	}
	else if (vars->map[i][j] == 'W')
	{
		vars->dirX = i;
		vars->dirY = j - 1;
	}
}

void	get_player_pos(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
				|| vars->map[i][j] == 'E' || vars->map[i][j] == 'W')
			{
				vars->player_pos[0] = i;
				vars->posX = i;
				vars->posY = j;
				vars->player_pos[1] = j;
				get_directions(vars, i, j);
			}
			j++;
		}
		i++;
	}
}

void	init(t_vars *vars, char *str)
{
	int		fd;
	char	**file;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_fd();
	file = get_file(fd);
	if (!file)
	{
		free(vars);
		error_malloc(fd, NULL);
	}
	close(fd);
	vars->map = get_map(file);
	if (!vars->map)
	{
		free(vars);
		error_malloc(fd, file);
	}
	get_player_pos(vars);
	get_parameters(vars, file);
	ft_free(file);
	vars->planeX = 0;
	vars->planeY = 0.66;
	vars->textures = ft_calloc(1, sizeof(t_textures));
	if (!vars->textures)
		ft_free_vars(vars);
}
