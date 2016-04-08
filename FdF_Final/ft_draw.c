/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 10:26:10 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/08 16:24:53 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_draw_line(t_pts *pts, int i, t_data *data, int dirc)
{
	t_bre		bre;

	data->color = data->tmp_color;
	data->color_value = data->tmp_color_value;
	bre.x1 = pts[i].x;
	bre.y1 = pts[i].y;
	bre.x2 = dirc == VLD ? pts[i + 1].x : pts[i + data->tab[1]].x;
	bre.y2 = dirc == VLD ? pts[i + 1].y : pts[i + data->tab[1]].y;
	bre.dx = abs(bre.x2 - bre.x1);
	bre.dy = abs(bre.y2 - bre.y1);
	bre.sx = bre.x1 < bre.x2 ? 1 : -1;
	bre.sy = bre.y1 < bre.y2 ? 1 : -1;
	bre.error = (bre.dx > bre.dy ? bre.dx : -bre.dy) / 2;
	while (1)
	{
		ft_select_color(pts, data, i);
		mlx_pixel_put(data->mlx, data->win, bre.x1, bre.y1, data->color);
		data->color += data->color_value;
		if (data->color >= 0xFFFFFF)
			data->color -= data->color_value;
		if (bre.x1 == bre.x2 && bre.y1 == bre.y2)
			break ;
		ft_draw_line_bis(&bre);
	}
}

void			*ft_draw_line_bis(t_bre *bre)
{
	bre->error_2 = bre->error;
	if (bre->error_2 > -bre->dx)
	{
		bre->error -= bre->dy;
		bre->x1 += bre->sx;
	}
	if (bre->error_2 < bre->dy)
	{
		bre->error += bre->dx;
		bre->y1 += bre->sy;
	}
	return (0);
}

void			ft_select_draw(t_pts *pts, int *tab, t_data *data)
{
	int	i;

	i = 0;
	while (i + 1 < (tab[0] * tab[1]))
	{
		if ((i + tab[1]) < (tab[0] * tab[1]))
			ft_draw_line(pts, i, data, VLB);
		if ((i + 1) % tab[1] != 0)
			ft_draw_line(pts, i, data, VLD);
		i++;
	}
}
