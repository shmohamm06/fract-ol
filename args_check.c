/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 08:47:29 by shmohamm          #+#    #+#             */
/*   Updated: 2024/03/07 15:27:54 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_select(char **argv, t_data *data)
{
	if (!argv[2])
	{
		write(1, "Please provide a Julia type argument\n", 38);
		return (exit(0), 0);
	}
	else if (ft_strcmp(argv[2], "1") == 0)
		julia_init1(data);
	else if (ft_strcmp(argv[2], "2") == 0)
		julia_init2(data);
	else if (ft_strcmp(argv[2], "3") == 0)
		julia_init3(data);
	else
	{
		write(1, "Use appropriate arguments for the Julia set:\n", 46);
		write(1, "\tEither 1, 2  or 3\n", 20);
		return (free(data), exit(0), 0);
	}
	return (1);
}

int	initialize_fractal_type(int argc, char **argv, t_data *data)
{
	if (!data)
		return (exit(0), 0);
	else if (argc == 2 && ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		data->fractol = 0;
		mandelbrot_init(data);
	}
	else if (argc == 2 && ft_strcmp(argv[1], "tricorn") == 0)
	{
		data->fractol = 2;
		tricorn_init(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->fractol = 1;
		julia_select(argv, data);
	}
	else
	{
		write(1, "Please try using the mentioned fractals:\n", 42);
		write(1, "\tmandelbrot, julia or tricorn\n", 28);
		return (free(data), exit(0), 0);
	}
	return (1);
}

int	validate_arguments(int argc)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Invalid number of arguments\n", 28);
		write(1, "Usage: ./executable fractal_type [julia_type]\n", 46);
		return (0);
	}
	return (1);
}

int	fract_select(int argc, char **argv, t_data *data)
{
	if (!validate_arguments(argc))
		return (free(data), exit(0), 0);
	if (!initialize_fractal_type(argc, argv, data))
		return (free(data), exit(0), 0);
	return (1);
}
