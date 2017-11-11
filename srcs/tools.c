/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:49:12 by enunes            #+#    #+#             */
/*   Updated: 2017/10/31 21:14:44 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_close(void)
{
	system("killall afplay");
	exit(1);
	return (0);
}

void	error(char *message)
{
	ft_putendl_fd("\e[1;31m", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(1);
}

void	help_text(t_wolf *t)
{
	mlx_string_put(t->mlx, t->win, 10, 10,
			0xf2f2f2, "Press W A S D or the arrow keys to move");
	mlx_string_put(t->mlx, t->win, 10, 30, 0xf2f2f2, "Press SHIFT to sprint");
	mlx_string_put(t->mlx, t->win, 10, 50,
			0xf2f2f2, "Press T to show or hide textures");
	mlx_string_put(t->mlx, t->win, 10, 70,
			0xf2f2f2, "Press H to show or hide this help");
	mlx_string_put(t->mlx, t->win, 10, 90,
			0xf2f2f2, "Press ESC to quit");
}

int	  line_len(char *str)
{
	int	n;

	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	return (n);
}

int		count_lines(char *str)
{
	int		n;

	n = 0;
	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == '\n')
			n++;
		str++;
	}
	return (n);
}
