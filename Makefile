# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 18:20:37 by oel-bour          #+#    #+#              #
#    Updated: 2021/11/09 21:49:23 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = g++
# COMPILER = clang++

FLAGS =
# FLAGS = --std=c++98 -Wall -Wextra -Werror

NAME = std.out ft.out vector.out map.out stack.out 
all: $(NAME)
$(NAME):
	@$(COMPILER) $(FLAGS) -D NS=0 main.cpp -o std.out && ./std.out > std.txt
	@$(COMPILER) $(FLAGS) -D NS=1 main.cpp -o ft.out && ./ft.out > ft.txt
	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out 
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 
	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out  
clean:
	@rm -f vector.out map.out stack.out std.out ft.out std.txt ft.txt
re: clean all