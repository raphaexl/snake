/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:13:11 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/14 16:45:51 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "snake.h"

int		ft_init_ncurses(void)
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(FALSE);
	return (SUCCESS);
}

int		ft_end_game(t_point *p, int ch)
{
	if (ch == KEY_F(1))
		return (TRUE);
	if (p->x < 0 || p->x > COLS)
		return (TRUE);
	if (p->y < 0 || p->y > LINES)
		return (TRUE);
	return (FALSE);
}

void	ft_snake_init(t_snake **snake, t_direction *d, t_point *food)
{
	ft_init_ncurses();
	*snake = NULL;
	*d = RIGHT;
	ft_setpoint(food, ft_randint(0, COLS - 1), ft_randint(0, LINES - 1));
	ft_snake_push_front(snake, *food);
	return ;
}

void	ft_snake_quit(t_snake **snake)
{
	ft_snake_clear(snake);
	endwin();
}

int		main(void)
{
	int			ch;
	int			quit;
	t_snake		*snake;
	t_point		food;
	t_direction	d;

	ft_snake_init(&snake, &d, &food);
	quit = FALSE;
	while (!quit)
	{
		ch = getch();
		clear();
		timeout(10);
		ft_setdirection(&d, &snake->pos, ch);
		ft_snake_draw(snake, food);
		ft_snake_move(&snake, snake->pos, &food);
		usleep(DELAY);
		refresh();
		quit = ft_end_game(&snake->pos, ch);
	}
	ft_snake_quit(&snake);
	return (SUCCESS);
}
