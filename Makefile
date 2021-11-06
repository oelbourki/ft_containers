# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 18:20:37 by oel-bour          #+#    #+#              #
#    Updated: 2021/11/06 14:27:01 by oel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++
FLAGS = --std=c++98 -Wall -Wextra -Werror
NAME = std
all: $(NAME)
$(NAME):
	@$(COMPILER) $(FLAGS) -D NS=0 main.cpp -o std.out && ./std.out > std.txt
	@$(COMPILER) $(FLAGS) -D NS=1 main.cpp -o ft.out && ./ft.out > ft.txt
	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out 
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 
# vector:
# 	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out 

# map:
# 	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 

# stack:
# 	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out 

clean:
	@rm -f vector.out map.out stack.out std.out ft.out std.txt ft.txt