/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 14:48:46 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/25 13:26:06 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_select_color(t_pts *pts, t_data *data, int i)
{
	if (pts[i].z_value < 0)
		data->color += 0x6600FF;
	if (pts[i].z_value > 0 && pts[i].z_value <= 5)
		data->color += 0xFF0000;
	if (pts[i].z_value > 5 && pts[i].z_value <= 10)
		data->color += 0xFFFFFF;
	if (pts[i].z_value > 10)
		data->color += 0x003CE5;
}
