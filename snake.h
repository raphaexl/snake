/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:17:16 by ebatchas          #+#    #+#             */
/*   Updated: 2018/10/14 16:33:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# define TRUE (1)
# define FALSE (0)
# define SUCCESS (0)
# define FAILURE (-1)
# define DELAY 42000

# include <ncurses.h>
# include <time.h>
# include "libft.h"

typedef enum		e_direction
{
	LEFT, RIGHT, UP, DOWN
}					t_direction;

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_snake
{
	t_point			pos;
	struct s_snake	*next;
}					t_snake;

t_snake				*ft_snake_create(void);
void				ft_snake_push_front(t_snake **snake, t_point p);
void				ft_snake_pop_back(t_snake **snake);
void				ft_snake_move(t_snake **snake, t_point p, t_point *food);
void				ft_snake_clear(t_snake **snake);

void				ft_snake_draw(t_snake *snake, t_point food);
void				ft_setpoint(t_point *p, int x, int y);
void				ft_setdirection(t_direction *d, t_point *p, int ch);
void				ft_snake_init(t_snake **snk, t_direction *d, t_point *f);
void				ft_snake_quit(t_snake **snake);
int					ft_end_game(t_point *p, int ch);
int					ft_randint(int min, int max);
int					ft_collision(t_point a, t_point b);
#endif
