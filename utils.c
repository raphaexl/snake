/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:44:46 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/14 16:20:31 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int		ft_randint(int min, int max)
{
	int		initialized;

	initialized = FALSE;
	if (!initialized)
	{
		srand(time(NULL));
		initialized = TRUE;
	}
	return (rand() % (max - min) + min);
}

int		ft_collision(t_point a, t_point b)
{
	return ((a.x == b.x) && (a.y == b.y));
}

void	ft_snake_draw(t_snake *snake, t_point food)
{
	t_snake *p;

	p = snake;
	while (p)
	{
		mvaddch(p->pos.y, p->pos.x, 'x');
		mvaddch(food.y, food.x, 'O');
		p = p->next;
	}
}

void	ft_setpoint(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

void	ft_setdirection(t_direction *d, t_point *p, int ch)
{
	if (ch == KEY_LEFT)
		*d = LEFT;
	else if (ch == KEY_RIGHT)
		*d = RIGHT;
	else if (ch == KEY_DOWN)
		*d = DOWN;
	else if (ch == KEY_UP)
		*d = UP;
	if (*d == LEFT)
		p->x--;
	else if (*d == RIGHT)
		p->x++;
	else if (*d == UP)
		p->y--;
	else
		p->y++;
}
