/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:02:26 by 42ad              #+#    #+#             */
/*   Updated: 2024/01/11 09:53:37 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init1(t_data *data)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->color = 0xd7afd7;
	data->zoom = 1;
	data->cre = -0.7;
	data->cim = 0.27015;
	data->newre = 0;
	data->newim = 0;
	data->oldre = 0;
	data->oldim = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->max_n = 300;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Julia Set 1");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_l, &data->endian);
	julia(data);
}

void	julia_init2(t_data *data)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->color = 0xd7afd7;
	data->zoom = 1;
	data->cre = -0.8;
	data->cim = 0.156;
	data->newre = 0;
	data->newim = 0;
	data->oldre = 0;
	data->oldim = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->max_n = 300;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Julia Set 2");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_l, &data->endian);
	julia(data);
}

void	julia_init3(t_data *data)
{
	data->width = WIDTH;
	data->height = HEIGHT;
	data->color = 0xd7afd7;
	data->zoom = 1;
	data->cre = -1.476;
	data->cim = 0;
	data->newre = 0;
	data->newim = 0;
	data->oldre = 0;
	data->oldim = 0;
	data->center_x = 0;
	data->center_y = 0;
	data->max_n = 300;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Julia Set 3");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->data = (int *)mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->size_l, &data->endian);
	julia(data);
}

int	julia_n(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->max_n && data->newre * data->newre + data->newim
		* data->newim < 4)
	{
		data->oldre = data->newre;
		data->oldim = data->newim;
		data->newre = data->oldre * data->oldre - data->oldim * data->oldim
			+ data->cre;
		data->newim = 2 * data->oldre * data->oldim + data->cim;
		i++;
	}
	return (i);
}

void	julia(t_data *data)
{
	int	n;
	int	x;
	int	y;

	x = 100;
	y = 100;
	while (y < data->height)
	{
		while (x < data->width)
		{
			data->newre = 1.5 * (x - data->width / 2 + data->center_x
					* data->width) / (0.3 * data->zoom * data->width);
			data->newim = (y - data->height / 2 + data->center_y * data->height)
				/ (0.3 * data->zoom * data->height);
			n = julia_n(data);
			data->data[y * WIDTH + x] = data->color * n;
			x++;
		}
		y++;
		x = 100;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
