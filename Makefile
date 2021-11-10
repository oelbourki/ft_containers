# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-bour <oel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 18:20:37 by oel-bour          #+#    #+#              #
#    Updated: 2021/11/10 09:42:50 by oel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILER = clang++

FLAGS = --std=c++98 -Wall -Wextra -Werror

NAME = std.out ft.out vector.out map.out stack.out set.out
all: $(NAME)
$(NAME):
	@$(COMPILER) $(FLAGS) -D NS=0 main.cpp -o std.out && ./std.out > std.txt
	@$(COMPILER) $(FLAGS) -D NS=1 main.cpp -o ft.out && ./ft.out > ft.txt
	@$(COMPILER) $(FLAGS)	Vector_tests.cpp -o vector.out 
	@$(COMPILER) $(FLAGS)	Map_tests.cpp -o map.out 
	@$(COMPILER) $(FLAGS)	Set_tests.cpp -o set.out 
	@$(COMPILER) $(FLAGS)	Stack_tests.cpp -o stack.out  
clean:
	@rm -f $(NAME)
fclean: clean
	@rm -f ft.txt std.txt
re: clean all