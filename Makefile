# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 17:33:24 by leng-chu          #+#    #+#              #
#    Updated: 2021/08/25 17:16:14 by leng-chu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
SRC		= ft_pipex.c ft_execute.c ft_utils.c main.c
#BONUS	=
CC		= gcc -Wall -Wextra -Werror
OBJ		= $(SRC:%.c=%.o)
OBJB	= $(BONUS:%.c=%.o)
RM		= rm -rf
LIBFT	:= libft
LIBFT_L	:= ./libft/libft.a

all:		libft $(NAME)

libft:
			@$(MAKE) -C $(LIBFT)

$(OBJ):		$(SRC)
			@$(CC) -I. -c $^

$(OBJB):	$(BONUS)
			@$(CC) -I. -c $^

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LIBFT_L)

clean:		
			make -C $(LIBFT) clean
			@$(RM) $(OBJ) $(OBJB)

fclean:		clean
			make -C $(LIBFT) fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus libft
