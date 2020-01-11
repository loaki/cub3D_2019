/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:06:41 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/01/11 15:48:59 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_size_wall_xp(t_data *data, double x, double y)
{
	double i;

	i = 0;
	while (i < data->width || i < data->height)
	{
		x = (int)ceil(data->pos_x) + i;
		y = data->pos_y - fabs(x - (double)data->pos_x) / data->vector_x_mod *
		data->vector_y_mod;
		if ((int)(y) <= (data->height - 1) && (int)(x) <=
			(data->width - 1) && (int)(y) >= 0 && (int)(x) >= 0 &&
			data->map[(int)(y)][(int)(x)] == '1')
			return ((double)data->res_y / (sqrtf(((double)data->pos_x - x) *
			((double)data->pos_x - x) + ((double)data->pos_y - y) *
			((double)data->pos_y - y))));
		i++;
	}
	return (0);
}

double	ft_size_wall_xn(t_data *data, double x, double y)
{
	double i;

	i = 0;
	while (i < data->width || i < data->height)
	{
		x = (int)(data->pos_x) - i;
		y = data->pos_y + fabs(x - (double)data->pos_x) / data->vector_x_mod *
		data->vector_y_mod;
		if ((int)(x) <= data->width && (int)(y) <=
			(data->height - 1) && (int)(x) >= 1 && (int)(y) >= 0 &&
			data->map[(int)(y)][(int)(x - 1)] == '1')
			return ((double)data->res_y / (sqrtf(((double)data->pos_x - x) *
			((double)data->pos_x - x) + ((double)data->pos_y - y) *
			((double)data->pos_y - y))));
		i++;
	}
	return (0);
}

double	ft_size_wall_yp(t_data *data, double x, double y)
{
	double i;

	i = 0;
	while (i < data->width || i < data->height)
	{
		y = (int)(data->pos_y) - i;
		x = data->pos_x + fabs(y - (double)data->pos_y) / data->vector_y_mod *
		data->vector_x_mod;
		if ((int)(x) <= (data->width - 1) && (int)(y) <=
			data->height && (int)(x) >= 0 && (int)(y) >= 1 &&
			data->map[(int)(y - 1)][(int)(x)] == '1')
			return ((double)data->res_y / (sqrtf(((double)data->pos_x - x) *
			((double)data->pos_x - x) + ((double)data->pos_y - y) *
			((double)data->pos_y - y))));
		i++;
	}
	return (0);
}

double	ft_size_wall_yn(t_data *data, double x, double y)
{
	double i;

	i = 0;
	while (i < data->width || i < data->height)
	{
		y = (int)ceil(data->pos_y) + i;
		x = data->pos_x - fabs(y - (double)data->pos_y) / data->vector_y_mod *
		data->vector_x_mod;
		if ((int)(x) <= (data->width - 1) && (int)(y) <=
			(data->height - 1) && (int)(x) >= 0 && (int)(y) >= 0 &&
			data->map[(int)(y)][(int)(x)] == '1')
			return ((double)data->res_y / (sqrtf(((double)data->pos_x - x) *
			((double)data->pos_x - x) + ((double)data->pos_y - y) *
			((double)data->pos_y - y))));
		i++;
	}
	return (0);
}
