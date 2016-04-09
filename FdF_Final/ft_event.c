/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 13:17:49 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/09 14:34:09 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_event(int keycode, void *param)
{
	t_data		*data;
	int			i;

	i = 0;
	data = param;
	if (keycode == 53)
		exit(0);
	if (ft_key_select(keycode) == 1)
	{
		ft_event_key_color(keycode, data);
		ft_event_key_move(keycode, data);
		ft_modify_tab_bis(data->pts, data->tab, data);
		mlx_clear_window(data->mlx, data->win);
		ft_select_draw(data->pts, data->tab, data);
		ft_put_hud(data);
	}
	return (0);
}

int				ft_event_key_move(int keycode, t_data *data)
{
	data->tmp_x = 0;
	data->tmp_y = 0;
	data->value = 1;
	if (keycode == 0)
		data->tmp_x = -20;
	if (keycode == 2)
		data->tmp_x = 20;
	if (keycode == 1)
		data->tmp_y = 20;
	if (keycode == 13)
		data->tmp_y = -20;
	if (keycode == 125)
		data->value = 0.5;
	if (keycode == 126)
		data->value = 1.5;
	return (0);
}

int				ft_event_key_color(int keycode, t_data *data)
{
	if (keycode == 78)
		data->tmp_color_value += 120;
	if (keycode == 69)
		data->tmp_color_value -= 120;
	if (keycode == 83)
		data->tmp_color = 0xFF0000;
	if (keycode == 84)
		data->tmp_color = 0x6600FF;
	if (keycode == 85)
		data->tmp_color = 0x003CE5;
	return (0);
}

int				ft_key_select(int keycode)
{
	if (keycode == 78 || keycode == 69 || keycode == 83 || keycode == 84 ||
		keycode == 85 || keycode == 0 || keycode == 1 || keycode == 2 ||
		keycode == 13 || keycode == 126 || keycode == 125)
		return (1);
	return (0);
}
