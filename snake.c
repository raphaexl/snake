/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:34:52 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/14 16:33:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

t_snake				*ft_snake_create(void)
{
	t_snake			*new;

	new = NULL;
	if ((new = (t_snake *)malloc(sizeof(*new))))
		return (new);
	return (new);
}

void				ft_snake_push_front(t_snake **snake, t_point p)
{
	t_snake		*new;

	new = NULL;
	if ((new = ft_snake_create()))
	{
		new->pos = p;
		new->next = *snake;
	}
	*snake = new;
}

void				ft_snake_pop_back(t_snake **snake)
{
	t_snake		*p;
	t_snake		*q;

	if (!snake || !*snake)
		return ;
	p = *snake;
	while (p->next)
	{
		q = p;
		p = p->next;
	}
	if (p)
		free(p);
	if (q && p)
		q->next = NULL;
}

void				ft_snake_move(t_snake **snake, t_point p, t_point *food)
{
	ft_snake_push_front(snake, p);
	if (ft_collision(p, *food))
	{
		ft_snake_push_front(snake, p);
		ft_setpoint(food, ft_randint(0, COLS - 1), ft_randint(0, LINES - 1));
		addch('\a');
	}
	ft_snake_pop_back(snake);
}

void				ft_snake_clear(t_snake **snake)
{
	t_snake *p;

	p = *snake;
	while (p)
	{
		*snake = (*snake)->next;
		free(p);
		p = *snake;
	}
	*snake = NULL;
}
