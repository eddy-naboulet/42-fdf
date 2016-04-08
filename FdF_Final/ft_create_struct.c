/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 10:16:09 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/08 16:15:17 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pts			*ft_create_struct(int *tab, char *av)
{
	t_pts		*new_tab;
	t_create	create;
	char		*line;
	char		**tab_line;

	new_tab = (t_pts*)ft_memalloc(sizeof(t_pts) * ((tab[0] * tab[1]) + 1));
	create.fd = open(av, O_RDONLY);
	create.all = 0;
	create.y = 0;
	while (create.y <= tab[0] - 1)
	{
		get_next_line(create.fd, &line);
		tab_line = ft_strsplit(line, ' ');
		create.x = 0;
		new_tab = ft_init_tab(new_tab, &create, tab_line);
		create.y++;
	}
	return (new_tab);
}

t_pts			*ft_init_tab(t_pts *new_tab, t_create *create, char **tab_line)
{
	while (tab_line[create->x])
	{
		new_tab[create->all].z = ft_atoi(tab_line[create->x]);
		if (new_tab[create->all].z <= -9999 || new_tab[create->all].z >= 9999)
		{
			ft_putendl("ERROR");
			exit(1);
		}
		new_tab[create->all].z_value = ft_atoi(tab_line[create->x]);
		new_tab[create->all].x = create->x;
		new_tab[create->all].y = create->y;
		create->x++;
		create->all++;
	}
	return (new_tab);
}
