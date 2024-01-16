/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:46:44 by shmohamm          #+#    #+#             */
/*   Updated: 2024/01/04 12:37:37 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	if ((fract_select(argc, argv, data)) == 0)
		return (-1);
	mlx_key_hook(data->win_ptr, keys, data);
	mlx_hook(data->win_ptr, 4, 0, mouse_hook, data);
	mlx_hook(data->win_ptr, 17, 0, close_button_hook, data);
	mlx_loop(data->mlx_ptr);
}
