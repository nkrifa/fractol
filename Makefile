# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkrifa <nkrifa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/09 13:47:47 by nkrifa            #+#    #+#              #
#    Updated: 2017/10/21 22:55:09 by nkrifa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = clang
LIB_NAME = ft
LIBDIR = libft
FLAGS = -Wall -Wextra -Werror -O3

HEADERS = includes/fractol.h

SOURCES = srcs/main.c \
		 

OBJECTS = $(SOURCES:.c=.o)

$(NAME): $(LIBDIR)/lib$(LIB_NAME).a $(OBJECTS)
	@$(CC) $(FLAGS) -L $(LIBDIR) -l $(LIB_NAME) -o $@ $^ -lmlx -framework OpenGL -framework AppKit
	@echo "./$(NAME) is ready, Use with '1' / '2' / '3' as param for Julia / Mandelbrot / Tricorn"

$(LIBDIR)/lib$(LIB_NAME).a : 
	@$(MAKE) -C $(LIBDIR)

all: $(NAME)

%.o: %.c $(HEADERS)/$(NAME).h
	@$(CC) $(FLAGS) -I $(HEADERS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)
	@make clean -C $(LIBDIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re

