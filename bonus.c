/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:35:22 by 42ad              #+#    #+#             */
/*   Updated: 2024/01/11 13:27:15 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_zoom(t_data *data)
{
	double	old_minreal;
	double	old_mini;

	old_minreal = data->minreal;
	old_mini = data->min_i;
	data->zoom *= 1.2;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mandelbrot(data);
}

void	ft_dezoom(t_data *data)
{
	double	old_minreal;
	double	old_mini;

	old_minreal = data->minreal;
	old_mini = data->min_i;
	data->zoom /= 1.2;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mandelbrot(data);
}

void	zoom_julia(t_data *data, int mousecode)
{
	double	old_zoom;

	old_zoom = data->zoom;
	if (mousecode == 4 || mousecode == 1)
	{
		data->zoom *= 1.2;
	}
	else if (mousecode == 5 || mousecode == 2)
	{
		data->zoom /= 1.2;
	}
	if (old_zoom != data->zoom)
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
	julia(data);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->fractol == 0)
	{
		if (mousecode == 5 || mousecode == 2)
			ft_zoom(data);
		else if (mousecode == 4 || mousecode == 1)
			ft_dezoom(data);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mandelbrot(data);
	}
	else if (data->fractol == 1)
		zoom_julia(data, mousecode);
	if (data->fractol == 2)
	{
		if (mousecode == 2 || mousecode == 5)
			data->zoom *= 1.2;
		else if (mousecode == 4 || mousecode == 1)
			data->zoom /= 1.2;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		tricorn(data);
	}
	return (0);
}

int	keys(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data);
		exit(0);
	}
	else if (key == 18)
		data->color = 0x00CED1;
	else if (key == 19)
		data->color = 0xff69b4;
	else if (key == 20)
		data->color = 0xffdab9;
	else if (key == 21)
		data->color = 0xd7afd7;
	else
		movement(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (data->fractol == 0)
		mandelbrot(data);
	else if (data->fractol == 1)
		julia(data);
	else if (data->fractol == 2)
		tricorn(data);
	return (0);
}
