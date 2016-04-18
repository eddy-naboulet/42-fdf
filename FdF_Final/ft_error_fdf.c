/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 16:13:31 by enaboule          #+#    #+#             */
/*   Updated: 2016/04/18 16:13:33 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *line, int i)
{
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isalpha(line[i]) && line[i] != ' '
	&& line[i] != '\n' && line[i] != '-')
		{
			ft_putendl("ERROR");
			exit(1);
		}
		i++;
	}
}
