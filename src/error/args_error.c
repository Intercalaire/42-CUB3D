/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:40:17 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/12 11:41:56 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	nb_arg_error(void)
{
	ft_putstr_fd("Error\nOnly one argument is required! ❌\n", 2);
	exit(1);
}

void	empty_arg(void)
{
	ft_putstr_fd("Error\nEmpty argument! ❌\n", 2);
	exit(1);
}

void	map_error(void)
{
	ft_putstr_fd("Error\nError occured on the map! ❌\n", 2);
	exit(1);
}
