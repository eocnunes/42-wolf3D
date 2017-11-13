/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:26:58 by enunes            #+#    #+#             */
/*   Updated: 2017/11/12 16:37:19 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	wolf3d_init(t_wolf *t)
{
	t->x_pos = 3;
	t->y_pos = 3;
	t->x_dir = -1;
	t->y_dir = 0;
	t->x_plane = 0;
	t->y_plane = 0.66;
	t->move_up = 0;
	t->move_down = 0;
	t->move_left = 0;
	t->move_right = 0;
	t->ms = 0.05;
	t->rs = 0.05;
	t->x_text = 0;
	t->y_text = 0;
	textures(t);
}

int		check_map(char *buff, t_wolf *t)
{
	int		i;
	int		len;

	len = 0;
	i = 0;
	t->map_width = line_len(buff);
	t->map_length = count_lines(buff);
	while (buff[i] && buff[i] != '\0')
	{
		if ((buff[i] < 48 || buff[i] > 57) && buff[i] != ' ' && buff[i] != '\n')
			return (0);
		len++;
		if (buff[i] == '\n')
		{
			if (len - 1 != t->map_width)
				return (0);
			len = 0;
		}
		i++;
	}
	return (1);
}

int		check_side(t_wolf *t)
{
	int		i;

	i = 0;
	while (i < t->map_width)
	{
		if (t->map[0][i] == 0)
			return (0);
		if (t->map[t->map_length - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < t->map_length)
	{
		if (t->map[i][0] == 0)
			return (0);
		if (t->map[i][t->map_width - 1] == 0)
			return (0);
		i++;
	}
	if (t->map[3][3] != 0)
		return (0);
	return (1);
}

int		parse_map(t_wolf *t, char **av)
{
	int		i;
	int		j;
	int		k;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		j = -1;
		k = 0;
		if (!(t->map[i] = (int *)malloc(sizeof(int) * t->map_width)))
			return (0);
		while (++j < t->map_width)
		{
			if (str[k] == ' ')
				k++;
			t->map[i][j] = ft_atoi(&str[k]);
			k++;
		}
		i++;
		free(str);
	}
	return (1);
}

int		parser(t_wolf *t, char **av)
{
	int		fd;
	char	*buff;
	int		i;

	i = 0;
	buff = ft_strnew(65536);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || (read(fd, buff, 65536)) < 1)
		error(ERR_MAP);
	(!(check_map(buff, t))) ? error(ERR_MAP) : (0);
	while (buff[i] != '\0' && buff[i] != '\n')
	{
		if (buff[i] == ' ')
			t->map_width--;
		i++;
	}
	ft_strdel(&buff);
	t->map_name = av[1];
	close(fd);
	if (!(t->map = (int **)malloc(sizeof(int *) * t->map_length)))
		return (0);
	if (!(parse_map(t, av)))
		return (0);
	(!check_side(t)) ? error(ERR_MAP) : (0);
	return (1);
}
