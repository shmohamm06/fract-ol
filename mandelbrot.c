/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:00:30 by 42ad              #+#    #+#             */
/*   Updated: 2024/01/16 13:12:07 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_data *data)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->minreal = -2.05;
	data->maxreal = 1.2;
	data->min_i = -1.3;
	data->max_i = 1.2;
	data->color = 0xd7afd7;
	data->zoom = 200;
	data->max_n = 200;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Mandelbrot");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_l, &data->endian);
	mandelbrot(data);
}

int	find_n(double cr, double ci, double max_n)
{
	int		i;
	double	zr;
	double	zi;
	double	temp;

	i = 0;
	zr = 0;
	zi = 0;
	while (i < max_n && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}

void	mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int	n;

	x = 100;
	while (x < data->width)
	{
		y = 100;
		while (y < data->height)
		{
			data->cre = find_real(x, data) * data->zoom * 0.008;
			data->cim = find_imaginary(y, data) * data->zoom * 0.008;
			n = find_n(data->cre, data->cim, data->max_n);
			data->data[y * WIDTH + x] = data->color * n;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

double	find_real(int x, t_data *data)
{
	double	range;

	range = data->maxreal - data->minreal;
	return (x * (range / data->width) + data->minreal);
}

double	find_imaginary(int y, t_data *data)
{
	double	range;

	range = data->max_i - data->min_i;
	return (y * (range / data->height) + data->min_i);
}
