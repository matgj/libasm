# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 15:36:41 by Mathis            #+#    #+#              #
#    Updated: 2020/04/29 14:55:39 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

CFLAGS = -Wall -Werror -Wextra

SFLAGS = -f elf64

OBJS = $(SRCS:.s=.o)

all : $(NAME)

$(NAME): $(OBJS) Makefile
	ar rcs $(NAME) $(OBJS)

%.o: %.s
	nasm $(SFLAGS) $< -o $@

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@/bin/rm -f $(NAME)

re : 
	@make fclean all

correc:
	@make fclean all
	clang $(CFLAGS) -c main.c
	clang $(CFLAGS) main.o $(NAME)