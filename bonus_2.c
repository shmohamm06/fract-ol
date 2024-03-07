/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:41:09 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/07 15:28:05 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fractal(t_data *data, double dx, double dy)
{
	double	range_real;
	double	range_imag;

	range_real = data->maxreal - data->minreal;
	range_imag = data->max_i - data->min_i;
	data->minreal += dx * range_real;
	data->maxreal += dx * range_real;
	data->min_i += dy * range_imag;
	data->max_i += dy * range_imag;
}

void	move_julia(t_data *data, double dx, double dy)
{
	data->center_x += dx / (data->zoom);
	data->center_y += dy / (data->zoom);
}

void	movement(int key, t_data *data)
{
	if (data->fractol == 0 || data->fractol == 2)
	{
		if (key == 13)
			move_fractal(data, 0, 0.1);
		else if (key == 2)
			move_fractal(data, -0.1, 0);
		else if (key == 1)
			move_fractal(data, 0, -0.1);
		else if (key == 0)
			move_fractal(data, 0.1, 0);
	}
	else if (data->fractol == 1)
	{
		if (key == 1)
			move_julia(data, 0, -0.1);
		else if (key == 2)
			move_julia(data, -0.1, 0);
		else if (key == 13)
			move_julia(data, 0, 0.1);
		else if (key == 0)
			move_julia(data, 0.1, 0);
	}
}

int	close_button_hook(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
	exit(0);
	return (0);
}
