/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 12:06:40 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/27 10:58:48 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_vars(t_vars *vars)
{
	if (vars->map)
		ft_free(vars->map);
	if (vars->north)
		free(vars->north);
	if (vars->south)
		free(vars->south);
	if (vars->east)
		free(vars->east);
	if (vars->west)
		free(vars->west);
	if (vars->textures->tmp_player_on_map)
		mlx_delete_texture(vars->textures->tmp_player_on_map);
	if (vars->textures)
		free(vars->textures);
	if (vars->player_on_map)
		mlx_delete_image(vars->window, vars->player_on_map);
	if (vars->mini_map)
		mlx_delete_image(vars->window, vars->mini_map);
	if (vars->cursor)
		free(vars->cursor); // Maybe sa degage et y a des probleme partout
	if (vars)
	{
		free(vars);
		vars = NULL;
	}
}
