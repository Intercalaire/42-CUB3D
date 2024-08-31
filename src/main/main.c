/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 09:37:13 by rgobet            #+#    #+#             */
/*   Updated: 2024/08/28 14:56:27 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <unistd.h>

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	move_player_on_map(t_vars *vars, int move, char pos)
{
	if (pos == 'y')
		vars->player_on_map->instances->y += move;
	else
		vars->player_on_map->instances->x += move;
}

void	key_recorder(void *param)
{
	int		tmp;
	t_vars	*vars;

	tmp = 0;
	vars = (t_vars *)param;
	if (mlx_is_key_down(vars->window, MLX_KEY_ESCAPE))
	{
		mlx_close_window(vars->window); // Add free ..
										// ft_free_vars(vars);
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_W))
	{
		vars->posX -= 0.02; // Verif les wall avant
		move_player_on_map(vars, -1, 'y');
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_S))
	{
		vars->posX += 0.02;
		move_player_on_map(vars, 1, 'y');
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_A))
	{
		vars->posX -= 0.02;
		move_player_on_map(vars, -1, 'x');
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_D))
	{
		vars->posX += 0.02;
		move_player_on_map(vars, 1, 'x');
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_RIGHT))
	{
		tmp = vars->dirX;
		vars->dirX = vars->dirX * cos(-ROT_SPEED) - vars->dirY
			* sin(-ROT_SPEED);
		vars->dirY = tmp * sin(-ROT_SPEED) + vars->dirY * cos(-ROT_SPEED);
		tmp = vars->planeX;
		vars->planeX = vars->planeX * cos(-ROT_SPEED) - vars->planeY
			* sin(-ROT_SPEED);
		vars->planeY = tmp * sin(-ROT_SPEED) + vars->planeY * cos(-ROT_SPEED);
		// tmp = vars->dirY;
		// if (vars->dirX >= 0)
		// 	vars->dirY += -0.1;
		// else
		// 	vars->dirY += 0.1;
		// if (tmp >= 0)
		// 	vars->dirX += -0.1;
		// else
		// 	vars->dirX += 0.1;
		printf("dirX/Y: %lf, %lf ; planeX/Y: %lf, %lf\n", vars->dirX,
			vars->dirY, vars->planeX, vars->planeY);
	}
	if (mlx_is_key_down(vars->window, MLX_KEY_LEFT))
	{
		tmp = vars->dirX;
		vars->dirX = vars->dirX * cos(ROT_SPEED) - vars->dirY * sin(ROT_SPEED);
		vars->dirY = tmp * sin(ROT_SPEED) + vars->dirY * cos(ROT_SPEED);
		tmp = vars->planeX;
		vars->planeX = vars->planeX * cos(ROT_SPEED) - vars->planeY
			* sin(ROT_SPEED);
		vars->planeY = tmp * sin(ROT_SPEED) + vars->planeY * cos(ROT_SPEED);
		// tmp = vars->dirY;
		// if (vars->dirX >= 0)
		// 	vars->dirY += 0.1;
		// else
		// 	vars->dirY += -0.1;
		// if (tmp >= 0)
		// 	vars->dirX += 0.1;
		// else
		// 	vars->dirX += -0.1;
		printf("dirX/Y: %lf, %lf ; planeX/Y: %lf, %lf\n", vars->dirX,
			vars->dirY, vars->planeX, vars->planeY);
	}
}

void	build_mini_map(t_vars *vars)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int32_t	color;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			color = -1;
			if (vars->map[x][y] == '1' || vars->map[x][y] == ' ')
				color = ft_pixel(255, 51, 51, 1000);
			else if (vars->map[x][y] == '0')
				color = ft_pixel(255, 255, 255, 0);
			else
				mlx_image_to_window(vars->window, vars->player_on_map, y * 6
					+ 20 - 2, x * 6 + 20 - 2);
			if (color == -1)
			{
				y++;
				continue ;
			}
			i = 0;
			while (i <= 10)
			{
				j = 0;
				while (j++ <= 10)
					mlx_put_pixel(vars->mini_map, y * 6 + i, x * 6 + j, color);
				i++;
			}
			y++;
		}
		x++;
	}
}

double	dist = 4;

void	display_wall(t_vars *vars)
{
	static int	test;
	static mlx_image_t	*tmp;
	double	calc;
	double	x;
	int		j;
	int		i;

	if (test != 0)
		mlx_delete_image(vars->window, tmp);
	tmp = mlx_new_image(vars->window, WIDTH, HEIGHT);
	mlx_image_to_window(vars->window, tmp, 0, 0);
		// printf("INIT\n");
	// while (vars->map[(int)(vars->dirX + dist - 1)][(int)vars->dirY] != '1')
	// 	dist++;
	printf("dist: %lf\n", dist);
	calc = (SCREEN * (WALL_HEIGHT / dist));
	printf("%lf\n", calc);
	j = 0;
	while (j <= WIDTH)
	{
		x = 0;
		i = 0;
		while (x < VIEW_HEIGHT - calc / 2) // Interval plafond
		{
			if (i >= HEIGHT - 1)
				break ;
			mlx_put_pixel(tmp, j, i, ft_pixel(51, 51, 255, 1000));
			x += 0.001;
			i++;
		}
		while (x >= VIEW_HEIGHT - calc / 2 && VIEW_HEIGHT + calc / 2 >= x) // Interval mur
		{
			if (i >= HEIGHT - 1)
				break ;
			mlx_put_pixel(tmp, j, i, ft_pixel(255, 51, 51, 1000));
			x += 0.001;
			i++;
			// printf("%i, %lf\n", i, x);
		}
		while (x > VIEW_HEIGHT + calc / 2 && i < HEIGHT - 1) // Interval sol
		{
			if (i >= HEIGHT - 1)
				break ;
			mlx_put_pixel(tmp, j, i, ft_pixel(51, 255, 51, 1000));
			x += 0.001;
			i++;
			// printf("sol: %i, %lf\n", i, x);
		}
		// if (test != 0)
		// 	printf("%i\n", j);
		j++;
	}
	test++;
}

void	display_vertical_line(t_vars *vars, int x, int start, int end, int32_t color)
{
	static int	test;
	int	i;

	i = 0;
	if (start > end)
	{
		int tmp = start;
		start = end;
		end = tmp;
	}
	// printf("start: %i, end: %i\n", start, end);
	// exit(0);
	while (i < start) // Interval plafond
	{
		mlx_put_pixel(vars->tmp, x, i, color);
		// printf("%i, %i\n", i, x);
		i++;
	}
	while (i >= start && end >= i) // Interval mur
	{
		if (i >= HEIGHT - 1)
			break ;
		mlx_put_pixel(vars->tmp, x, i, color);
		// printf("%i, %i\n", i, x);
		i++;
	}
	while (i > end && i < HEIGHT - 1) // Interval sol
	{
		mlx_put_pixel(vars->tmp, x, i, color);
		// printf("sol: %i, %i\n", i, x);
		i++;
	}
	test++;
}

void	raycast(t_vars *vars, int i)
{
	int		hit;
	int		mapY;
	int		side;
	int		drawStart;
	int		drawEnd;
	int32_t	color;
	int		mapX;
	double	perpWallDist;
	int		lineHeight;

	(void)vars;
	// longueur du rayon de la position actuelle au côté x ou y suivant
	// dans quelle direction marcher dans la direction x ou y (soit +1 soit -1)
	hit = 0;
	mapX = 0;
	mapY = 0;
	vars->cameraX = 2 * i / (double)WIDTH - 1;
	vars->rayDirX = vars->dirX + vars->planeX * vars->cameraX;
	vars->rayDirY = vars->dirY + vars->planeY * vars->cameraX;
	// printf("rayDirX/Y: %lf, %lf\n", vars->rayDirX, vars->rayDirY);
	//
	mapX = (int)vars->posX;
	mapY = (int)vars->posY;
	if (vars->rayDirX == 0)
		vars->deltaDistX = MAX;
	else
		vars->deltaDistX = fabs(1 / vars->rayDirX);
	if (vars->rayDirY == 0)
		vars->deltaDistY = MAX;
	else
		vars->deltaDistY = fabs(1 / vars->rayDirY);
	// vars->deltaDistX = sqrt(1 + (vars->rayDirX* vars->rayDirY)/ (vars->rayDirX * vars->rayDirX));
	// vars->deltaDistY = sqrt(1 + (vars->rayDirX* vars->rayDirX)/ (vars->rayDirY * vars->rayDirY));
	if (vars->rayDirX < 0) // calculer le pas et le sideDist initial ??
	{
		vars->stepX = -1;
		vars->sideDistX = (vars->posX - mapX) * vars->deltaDistX;
	}
	else
	{
		vars->stepX = 1;
		vars->sideDistX = (mapX + 1.0 - vars->posX) * vars->deltaDistX;
	}
	if (vars->rayDirY < 0)
	{
		vars->stepY = -1;
		vars->sideDistY = (vars->posY - mapY) * vars->deltaDistY;
	}
	else
	{
		vars->stepY = 1;
		vars->sideDistY = (mapY + 1.0 - vars->posY) * vars->deltaDistY;
	}
	// DDA (Digital Differential Analyser)
	hit = 0;
	while (hit == 0) // y a-t-il eu un mur touché
	{
		// sauter au prochain carré de la carte, soit dans la direction x,	soit dans la direction y
		if (vars->sideDistX < vars->sideDistY)
		{
			vars->sideDistX += vars->deltaDistX;
			mapX += vars->stepX;
			side = 0; // y a-t-il eu un mur NS ou EW touché
		}
		else
		{
			vars->sideDistY += vars->deltaDistY;
			mapY += vars->stepY;
			side = 1;
		}
		if (vars->map[mapX][mapY] > 0)
			hit = 1;
			// vérifier si le rayon a heurté un mur
	}
	// Calculer la distance projetée sur la direction de la caméra (la distance euclidienne donnerait un effet fisheye !)
	printf("side %i\n", side);
	if (side == 0)
		perpWallDist = (vars->sideDistX - vars->deltaDistX);
	else
		perpWallDist = (vars->sideDistY - vars->deltaDistY);
	// Calculer la hauteur de la ligne à dessiner sur l'écran
	lineHeight = (int)(HEIGHT / perpWallDist);
	// Calculer les pixels les plus bas et les plus hauts pour remplir la bande actuelle
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	// Choisir la couleur du mur
	switch (vars->map[mapX][mapY])
	{
		case 1:
			color = ft_pixel(255, 0, 0, 1000);
			break ;
		case 2:
			color = ft_pixel(0, 255, 0, 1000);
			break ;
		case 3:
			color = ft_pixel(0, 0, 255, 1000);
			break ;
		case 4:
			color = ft_pixel(0, 0, 0, 1000);
			break ;
		default:
			color = ft_pixel(255, 150, 51, 1000);
			break ;
	}
	// if (side == 1)
		// color = ft_pixel(255, 255, 255, 1000);
		// dessiner les pixels de la bande sous forme de ligne verticale ???
	// Try de print la map
	// color = ft_pixel(200, 200, 80, 1000);
	printf("i: %i, drawStart: %i, drawEnd: %i\n", i, drawStart, drawEnd);
	display_vertical_line(vars, i, drawStart, drawEnd, color);
	// display_wall(vars);
}

void	mini_map(mlx_key_data_t key, void *param)
{
	t_vars	*vars;

	vars = param;
	if (key.key == MLX_KEY_M && key.action == MLX_PRESS)
	{
		vars->mini_map->enabled = !vars->mini_map->enabled;
		vars->player_on_map->enabled = !vars->player_on_map->enabled;
	}
	// if (key.key == MLX_KEY_R && key.action == MLX_PRESS)
	// 	raycast(vars);
	if (key.key == MLX_KEY_KP_SUBTRACT && key.action == MLX_PRESS && dist > 1)
		dist--;
	if (key.key == MLX_KEY_KP_ADD && key.action == MLX_PRESS)
		dist++;
}

void	paint_on_screen(t_vars *vars)
{
	int	i;
	int	x;
	// int	y;

	while (42)
	{
		i = 0;
		while (i < WIDTH)
		{
			vars->dirX = i;
			raycast(vars, i);
			i++;
		}
		printf("SORTIE\n");
		x = 0;
		// while (x < HEIGHT && vars->map[x])
		// {
		// 	if (x >= HEIGHT)
		// 		break ;
		// 	y = -1;
		// 	while (++y < WIDTH)
		// 	{
		// 		if (y >= WIDTH && vars->map[x][y])
		// 			break ;
		// 		printf("x: %i, y: %i\n", x, y);
		// 		display_vertical_line(vars, y, 0, HEIGHT, ft_pixel(255, 255, 255, 1000));
		// 	}
		// 	x++;
		// }
	}
	build_mini_map(vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	vars = NULL;
	if (ac != 2)
		nb_arg_error();
	parse_file(av[1]);
	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		error_malloc(-1, NULL);
	init(vars, av[1]);
	if (!vars)
		exit(1);
	vars->window = mlx_init(WIDTH, HEIGHT, "CUB3D", 1);
	if (!vars->window)
	{
		ft_putstr_fd("Error\nAn error occured while opening the window!\n", 2);
		ft_free_vars(vars);
		exit(1);
	}
	vars->mini_map = mlx_new_image(vars->window, 256, 256);
	if (!vars->mini_map)
	{
		ft_putstr_fd("Error\nAn error occurred while creating the mini map image!\n",
			2);
		ft_free_vars(vars);
		exit(1);
	}
	vars->textures->tmp_player_on_map = mlx_load_png("./textures/mini_map/player.png");
	if (!vars->textures->tmp_player_on_map)
	{
		ft_putstr_fd("Error\nAn error occurred while loading the player texture!\n",
			2);
		ft_free_vars(vars);
		exit(1);
	}
	vars->player_on_map = mlx_texture_to_image(vars->window,
			vars->textures->tmp_player_on_map);
	if (!vars->player_on_map)
	{
		ft_putstr_fd("Error\nAn error occurred while converting the player texture to image!\n",
			2);
		ft_free_vars(vars);
		exit(1);
	}
	vars->tmp = mlx_new_image(vars->window, WIDTH, HEIGHT);
	mlx_image_to_window(vars->window, vars->tmp, 0, 0);
	mlx_image_to_window(vars->window, vars->mini_map, 20, 20);
	paint_on_screen(vars);
	vars->cursor = mlx_create_std_cursor(MLX_CURSOR_CROSSHAIR);
	mlx_set_cursor(vars->window, vars->cursor);
	mlx_loop_hook(vars->window, (void *)key_recorder, vars);
	mlx_key_hook(vars->window, (void *)mini_map, vars);
	// mlx_put_pixel(NULL, 0, 0, 200);
	// void mlx_set_icon(mlx_t* mlx, mlx_texture_t* image);
	// mlx_cursor_hook(mlx_t* mlx, mlx_cursorfunc func,void* param); pour la position souris
	// int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x,int32_t y);
	// mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);
	// void mlx_delete_image(mlx_t* mlx, mlx_image_t* image);
	// void mlx_delete_texture(mlx_texture_t* texture);
	// void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y,uint32_t color);
	// void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);
	// void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param);
	// void mlx_set_cursor_mode(mlx_t* mlx, mouse_mode_t mode);-> mode == HIDDEN
	// const char* mlx_strerror(mlx_errno_t val); for error
	mlx_loop(vars->window);
	mlx_close_window(vars->window);
	mlx_terminate(vars->window);
	ft_free_vars(vars);
	return (0);
}
