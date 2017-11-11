/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enunes <eocnunes@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:26:58 by enunes            #+#    #+#             */
/*   Updated: 2017/10/31 21:14:44 by enunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_release(int keycode, t_wolf *t)
{
	if (keycode == 13 || keycode == 126)
		t->move_up = 0;
	else if (keycode == 1 || keycode == 125)
		t->move_down = 0;
	else if (keycode == 2 || keycode == 124)
		t->move_right = 0;
	else if (keycode == 0 || keycode == 123)
		t->move_left = 0;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.05;
	return (0);
}

int		key_press2(int keycode, t_wolf *t)
{
	if (keycode == 4)
	{
		if (t->help == 0)
			t->help = 1;
		else
			t->help = 0;
	}
	else if (keycode == 17)
	{
		if (t->texture == 0)
			t->texture = 1;
		else
			t->texture = 0;
	}
	return (0);
}

int		key_press(int keycode, t_wolf *t)
{
	if (keycode == 13 || keycode == 126)
		t->move_up = 1;
	else if (keycode == 1 || keycode == 125)
		t->move_down = 1;
	else if (keycode == 2 || keycode == 124)
		t->move_right = 1;
	else if (keycode == 0 || keycode == 123)
		t->move_left = 1;
	else if (keycode == 257 || keycode == 258)
		t->ms = 0.1;
	else if (keycode == 53)
		ft_close();
	else if (keycode == 117)
		wolf3d_init(t);
	else
		key_press2(keycode, t);
	return (0);
}
