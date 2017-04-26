/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoplavs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 12:21:19 by apoplavs          #+#    #+#             */
/*   Updated: 2017/04/05 12:21:31 by apoplavs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		set_number_of_player(char *line, t_data *info)
{
	if (line[0] == '$' && line[1] == '$' && line[2] == '$')
	{
		if (ft_strstr(line, "exec p1"))
			info->player = 1;
		if (ft_strstr(line, "exec p2"))
			info->player = 2;
		ft_strdel(&line);
	}
	else
	{
		perror("Error: no number of player");
		exit(1);
	}
}

int			set_map_size(char *line, t_data *info)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = ft_strsplit(line, ' ')) || !tab[0]
		|| !ft_strequ(tab[0], "Plateau") || !tab[1] || !tab[2])
		return (0);
	info->map_size.y = ft_atoi(tab[1]);
	info->map_size.x = ft_atoi(tab[2]);
	if ((info->map = (char**)malloc(sizeof(char*) * (info->map_size.y + 1)))
		== NULL)
		return (0);
	while (++i <= info->map_size.y)
		info->map[i] = NULL;
	info->step++;
	return (free_and_return(tab, 1));
}

int			fill_map(char *line, t_data *info)
{
	char	*p;
	int		i;

	i = 0;
	if (!(p = ft_strchr(line, ' ')))
		return (0);
	p++;
	while (info->map[i] != NULL)
		i++;
	info->map[i] = ft_strdup(p);
	if (i + 1 == info->map_size.y)
		info->step = 3;
	return (1);
}

int			set_piece_size(char *line, t_data *info)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = ft_strsplit(line, ' ')) || !tab[0]
		|| !ft_strequ(tab[0], "Piece") || !tab[1] || !tab[2])
		return (0);
	info->piece_size.y = ft_atoi(tab[1]);
	info->piece_size.x = ft_atoi(tab[2]);
	if ((info->piece = (char**)malloc(sizeof(char*) * (info->piece_size.y + 1)))
		== NULL)
		return (0);
	while (++i <= info->piece_size.y)
		info->piece[i] = NULL;
	info->step++;
	return (free_and_return(tab, 1));
}

int			fill_piece(char *line, t_data *info)
{
	int		i;

	i = 0;
	if ((int)ft_strlen(line) != info->piece_size.x)
		return (0);
	while (info->piece[i] != NULL)
		i++;
	info->piece[i] = ft_strdup(line);
	ft_strdel(&line);
	if (i + 1 == info->piece_size.y)
		info->step = 5;
	return (1);
}
