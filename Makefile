# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 18:20:37 by oel-bour          #+#    #+#              #
#    Updated: 2021/11/05 18:20:49 by oel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++
FLAGS = --std=c++98 -Wall -Wextra -Werror -fsanitize=address

vector:
	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out 

map:
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 

stack:
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

clean:
	rm -f vector.out map.out stack.out 