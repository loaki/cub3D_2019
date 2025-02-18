/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:49:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2020/02/10 18:09:44 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_atoi(char *str, int *i)
{
	unsigned int	c;

	c = 0;
	while (str[*i] == ' ')
		*i += 1;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		c = c * 10 + str[*i] - '0';
		*i += 1;
	}
	return (c);
}

char			*ft_linedup(char *str)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			len++;
		i++;
	}
	if (!(ret = malloc(len + 1)))
		return (0);
	while (i >= 0)
	{
		if (str[i] != ' ')
		{
			ret[len] = str[i];
			len--;
		}
		i--;
	}
	return (ret);
}

int				ft_parse_res(t_data *data, char *line)
{
	int i;

	i = 1;
	if (data->res_x != 0 || data->res_y != 0)
		return (EXIT_FAILURE);
	data->res_x = ft_atoi(line, &i);
	data->res_y = ft_atoi(line, &i);
	i++;
	if (data->res_x > 2560)
		data->res_x = 2560;
	if (data->res_y > 1440)
		data->res_y = 1440;
	if (line[i] != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				ft_parse_ceil(t_data *data, char *line)
{
	int i;
	int c;

	i = 1;
	if (data->ceil != 0)
		return (EXIT_FAILURE);
	c = ft_atoi(line, &i);
	if (c < 0 || c > 255)
		return (EXIT_FAILURE);
	data->ceil = c * 256 * 256;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	c = ft_atoi(line, &i);
	if (c < 0 || c > 255)
		return (EXIT_FAILURE);
	data->ceil += c * 256;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	c = ft_atoi(line, &i);
	if (c < 0 || c > 255)
		return (EXIT_FAILURE);
	data->ceil += c;
	if (line[i] != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int				ft_parse_floor(t_data *data, char *line)
{
	int i;
	int c;

	i = 1;
	if (data->floor != 0)
		return (EXIT_FAILURE);
	c = ft_atoi(line, &i);
	if (c < 0 || c > 255)
		return (EXIT_FAILURE);
	data->floor = c * 256 * 256;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	c = ft_atoi(line, &i);
	if (c < 0 || c > 255)
		return (EXIT_FAILURE);
	data->floor += c * 256;
	while (line[i] == ' ' || line[i] == ',')
		i++;
	c = ft_atoi(line, &i);
	if (c < 0 || c > 255)
		return (EXIT_FAILURE);
	data->floor += c;
	if (line[i] != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
