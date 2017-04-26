/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 17:02:06 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/05 17:02:24 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_distance(t_data *info, char rival_side)
{
	t_axis	*a;

	if ((a = malloc(sizeof(t_axis))) == NULL)
		return (0);
	a->y = -1;
	while (info->map[++a->y])
	{
		a->x = -1;
		while (info->map[a->y][++a->x])
		{
			if (info->map[a->y][a->x] == rival_side
				&& count_outage(info, *a, 0) > 0)
			{
				info->p = a;
				return (1);
			}
		}
	}
	free(a);
	return (0);
}

int			length(t_axis a, t_axis b)
{
	int		res;
	int		temp;

	res = b.x - a.x;
	temp = b.y - a.y;
	res *= res;
	temp *= temp;
	res += temp;
	return (res);
}

t_axis		find_place(t_data *info)
{
	t_axis a;
	t_axis p;

	a.y = -1;
	p.x = -1;
	p.y = -1;
	while (info->map[++a.y])
	{
		a.x = -1;
		while (info->map[a.y][++a.x])
		{
			if (is_can_insert_piece(a, info))
			{
				if ((p.y == -1 && p.x == -1)
					|| (get_distance(info, info->player == 1 ? 'X' : 'O')
						&& length(p, *info->p) > length(a, *info->p)))
					p = a;
			}
		}
	}
	return (p);
}

void		find_position(t_data *info)
{
	t_axis	position;

	position = find_place(info);
	ft_printf("%d %d\n", position.y, position.x);
	free_and_return(info->map, 0);
	free_and_return(info->piece, 0);
	free(info->p);
	set_default_data(info);
}

int			read_data(t_data *info)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (info->step == 0 && set_map_size(line, info))
			ft_strdel(&line);
		else if (info->step == 1 && info->step++)
			ft_strdel(&line);
		else if (info->step == 2 && fill_map(line, info))
			ft_strdel(&line);
		else if (info->step == 3 && set_piece_size(line, info))
			ft_strdel(&line);
		else if (info->step == 4 && fill_piece(line, info))
		{
			if (info->step == 5)
				find_position(info);
		}
		else
		{
			ft_strdel(&line);
			return (0);
		}
	}
	return (1);
}
