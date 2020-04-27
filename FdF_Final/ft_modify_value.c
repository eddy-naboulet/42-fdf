/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modify_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:06:28 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/18 14:06:32 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_select_value(t_data *data, int *tab)
{
	if (tab[1] >= 0 && tab[1] <= 20)
		ft_map_size_1(data, tab);
	if (tab[1] >= 21 && tab[1] <= 50)
		ft_map_size_2(data);
	if (tab[1] <= 200 && tab[1] >= 51)
		ft_map_size_3(data);
}

void		ft_map_size_1(t_data *data, int *tab)
{
	if (tab[0] == 11)
	{
		data->tmp_x = 30;
		data->tmp_y = 0;
		data->mult_z = 2;
		data->div_z = 30;
		data->value = 30;
	}
	else
	{
		data->tmp_x = 40;
		data->tmp_y = 2;
		data->mult_z = 20;
		data->div_z = 30;
		data->value = 30;
	}
}

void		ft_map_size_2(t_data *data)
{
	data->tmp_x = 30;
	data->tmp_y = -20;
	data->mult_z = 10;
	data->div_z = 30;
	data->value = 30;
}

void		ft_map_size_3(t_data *data)
{
	data->tmp_x = 80;
	data->tmp_y = -40;
	data->mult_z = 20;
	data->div_z = 30;
	data->value = 10;
}
