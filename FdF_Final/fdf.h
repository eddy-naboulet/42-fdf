/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 15:09:16 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/09 15:12:14 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define VLD 0
# define VLB 1

# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_bre
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				error;
	int				error_2;
}					t_bre;

typedef struct		s_pts
{
	float			x;
	float			y;
	float			z;
	float			z_value;
}					t_pts;

typedef struct		s_data
{
	int				color;
	int				tmp_color;
	int				color_value;
	int				tmp_color_value;
	int				pos_x;
	int				tmp_x;
	int				pos_y;
	int				tmp_y;
	float			value;
	float			mult_z;
	int				div_z;
	int				fd;
	int				cpt;
	int				x;
	int				y;
	int				i;
	void			*mlx;
	void			*win;
	int				*tab;
	t_bre			*bre;
	t_pts			*pts;
}					t_data;

typedef struct		s_create
{
	int				fd;
	int				x;
	int				all;
	int				y;
}					t_create;

t_pts				*ft_init_tab(t_pts *new_tab, t_create *create, char
					**lines);
t_pts				*ft_modify_tab_bis(t_pts *pts, int *tab, t_data *data);
t_pts				*ft_modify_tab(t_pts *pts, int *tab, t_data *data);
t_pts				*ft_create_struct(int *tab, char *av);
int					ft_event_key_color(int keycode, t_data *data);
int					ft_event_key_move(int keycode, t_data *data);
void				ft_error(char *line, int i);
int					ft_event(int keycode, void *param);
int					*ft_parse(char *av, t_data *data);
int					ft_key_select(int keycode);
void				ft_draw_line(t_pts *pts, int i, t_data *data, int dirc);
void				ft_modify_value(t_data *data, t_pts *pts, int *tab);
void				ft_select_value(t_data *data, int *tab);
void				ft_select_draw(t_pts *pts, int *tab, t_data *data);
void				ft_map_size_1(t_data *data, int *tab);
void				ft_map_size_2(t_data *data);
void				ft_map_size_3(t_data *data);
void				ft_select_color(t_pts *pts, t_data *data, int i);
void				ft_line_hud(t_data *data);
void				*ft_draw_line_bis(t_bre *bre);
void				ft_hud_move(t_data *data);
void				ft_put_hud(t_data *data);

#endif
