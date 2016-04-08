/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 10:23:21 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/08 10:23:33 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_pts		*pts;
	int			*tab;
	t_data		*data;

	(void)argc;
	data = ft_memalloc(sizeof(t_data));
	tab = ft_parse(argv[1], data);
	pts = ft_create_struct(tab, argv[1]);
	pts = ft_modify_tab(pts, tab, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1650, 1300, "fdf");
	data->tab = tab;
	data->tmp_color_value = 1200;
	data->pts = pts;
	ft_select_draw(pts, tab, data);
	mlx_hook(data->win, 2, 0, ft_event, data);
	ft_put_hud(data);
	mlx_loop(data->mlx);
	return (0);
}
