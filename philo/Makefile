# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dalonso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 13:16:08 by dalonso           #+#    #+#              #
#    Updated: 2021/07/31 13:16:12 by dalonso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo
SRCS = main.c parser.c day_cycle.c simulation.c utils.c
all: $(NAME)
$(NAME): $(SRCS)
	gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME)
clean:
	@rm -rf $(NAME)
re: clean
	gcc -Wall -Werror -Wextra $(SRCS) -o $(NAME) 
