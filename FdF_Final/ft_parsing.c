/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 10:08:37 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/08 16:30:29 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			*ft_parse(char *av, t_data *data)
{
	int		*tab;
	char	*line;
	char	**lines;
	int		i;

	i = 0;
	data->cpt = 0;
	data->y = 1;
	data->x = 0;
	data->fd = open(av, O_RDONLY);
	get_next_line(data->fd, &line);
	ft_error(line, i);
	lines = ft_strsplit(line, ' ');
	while (lines[data->x])
		data->x++;
	while (get_next_line(data->fd, &line) == 1)
		data->y++;
	close(data->fd);
	tab = malloc(sizeof(int) * 2);
	tab[0] = data->y;
	tab[1] = data->x;
	return (tab);
}

t_pts		*ft_modify_tab_bis(t_pts *pts, int *tab, t_data *data)
{
	data->i = 0;
	while (data->i < tab[0] * tab[1])
	{
		pts[data->i].x = (pts[data->i].x + data->tmp_x) * data->value;
		pts[data->i].y = (pts[data->i].y + data->tmp_y) * data->value;
		pts[data->i].z = ((pts[data->i].z / data->div_z) * data->mult_z)
		* data->value;
		data->i++;
	}
	return (pts);
}

t_pts		*ft_modify_tab(t_pts *pts, int *tab, t_data *data)
{
	data->i = 0;
	ft_select_value(data, tab);
	pts = ft_modify_tab_bis(pts, tab, data);
	data->i = 0;
	while (data->i < tab[0] * tab[1])
	{
		pts[data->i].x = -pts[data->i].x * cos((5 * M_PI_4)) - pts[data->i].y
			* cos(7 * M_PI_4);
		pts[data->i].y = -pts[data->i].z - pts[data->i].x * sin((5 * M_PI_4))
			- pts[data->i].y * sin(7 * M_PI_4);
		data->i++;
	}
	return (pts);
}
