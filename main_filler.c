/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_filler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 11:29:15 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/05 11:29:46 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			count_outage(t_data *info, t_axis a, int count)
{
	if ((a.y - 2) >= 0 && info->map[a.y - 1][a.x] == '.'
		&& info->map[a.y - 2][a.x] == '.')
		count++;
	if ((a.y + 2) < info->map_size.y && info->map[a.y + 1][a.x] == '.'
		&& info->map[a.y + 2][a.x] == '.')
		count++;
	if ((a.x - 2) >= 0 && info->map[a.y][a.x - 1] == '.'
		&& info->map[a.y][a.x - 2] == '.')
		count++;
	if ((a.x + 2) < info->map_size.x && info->map[a.y][a.x + 1] == '.'
		&& info->map[a.y][a.x + 2] == '.')
		count++;
	return (count > 1 ? 1 : 0);
}

int			is_can_insert_piece(t_axis a, t_data *info)
{
	t_axis	b;
	int		res;

	b.y = -1;
	res = 0;
	if ((info->map_size.x - a.x - info->piece_size.x) < 0
		|| (info->map_size.y - a.y - info->piece_size.y) < 0)
		return (0);
	while (info->piece[++b.y])
	{
		b.x = -1;
		while (info->piece[b.y][++b.x])
		{
			if (info->map[a.y + b.y][a.x + b.x] == info->side
				&& info->piece[b.y][b.x] == '*')
				res++;
			else if (info->map[a.y + b.y][a.x + b.x] != '.'
				&& info->piece[b.y][b.x] == '*')
				res = 2;
		}
	}
	return (res == 1 ? 1 : 0);
}

void		set_default_data(t_data *data)
{
	data->map_size.x = 0;
	data->map_size.y = 0;
	data->piece_size.x = 0;
	data->piece_size.y = 0;
	data->p = NULL;
	data->map = NULL;
	data->piece = NULL;
	data->step = 0;
}

int			free_and_return(char **point, int status)
{
	int		i;

	i = -1;
	while (point[++i])
		free(point[i]);
	free(point[i]);
	free(point);
	return (status);
}

int			main(void)
{
	t_data	info;
	char	*line;

	set_default_data(&info);
	info.player = 0;
	if (get_next_line(0, &line) > 0)
		set_number_of_player(line, &info);
	info.side = (info.player == 1) ? 'O' : 'X';
	return (read_data(&info) == 0 ? 1 : 0);
}
