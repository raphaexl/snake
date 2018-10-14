# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/14 11:06:22 by ebatchas          #+#    #+#              #
#    Updated: 2018/10/14 11:12:52 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=.
LIBDIR=.
HEADDIR=.
BINDIR=.

CFLAGS=-I$(HEADDIR) -Wall -Wextra -Werror
LDFLAGS=-I$(HEADDIR) -lncurses -L. -lft

SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC: $(SRCDIR)/%.c=$(LIBDIR)/%.o)
NAME=$(BINDIR)/snake

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o: $(HEADDIR)/%.h

$(LIBDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $< -c

.PHONY : clean fclean

clean:
	rm -rf $(LIBDIR)/%.o

fclean : clean
	rm -rf $(BINDIR)/$(NAME)

re: fclean all
