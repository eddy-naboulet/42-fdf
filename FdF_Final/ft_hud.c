/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:41:31 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/09 14:32:36 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_hud(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 15, 15, 0xFFFFFF, "press esc = quit");
	mlx_string_put(data->mlx, data->win, 15, 35, 0xFF0000,
		"press 1 = color profile 1");
	mlx_string_put(data->mlx, data->win, 15, 55, 0x6600FF,
		"press 2 = color profile 2");
	mlx_string_put(data->mlx, data->win, 15, 75, 0x003CE5,
		"press 3 = color profile 3");
	mlx_string_put(data->mlx, data->win, 15, 95, 0xFFFFFF,
		"press + / - = to change color");
	ft_line_hud(data);
	ft_hud_move(data);
}

void	ft_hud_move(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 15, 115, 0xFFFFFF,
		"press a / w / d / s = to move");
	mlx_string_put(data->mlx, data->win, 15, 135, 0xFFFFFF,
		"press up / down = to zoom / dezoom");
}

void	ft_line_hud(t_data *data)
{
	int		i;
	int		j;

	j = 10;
	i = 10;
	while (i < 150)
	{
		mlx_string_put(data->mlx, data->win, 5, i, 0xFFFFFF, "|");
		i += 10;
	}
	while (j < 150)
	{
		mlx_string_put(data->mlx, data->win, 365, j, 0xFFFFFF, "|");
		j += 10;
	}
	mlx_string_put(data->mlx, data->win, 5, 2, 0xFFFFFF,
		"+-----------------------------------+");
	mlx_string_put(data->mlx, data->win, 5, 150, 0xFFFFFF,
		"+-----------------------------------+");
}
