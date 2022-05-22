# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 02:30:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/05/22 06:27:52 by mmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______________________________________//_______________________________________
SRC_DIR		=	./ ./tests ./tests/components
SRC			=	main.cpp
TEST_SRC	=	teste.cpp \
				normal_iterator.cpp \
				normal_reverse_iterator.cpp \
				type_traits.cpp \
				utility.cpp \
				algorithm.cpp \
				vector.cpp \
				stack.cpp \
				rb_map.cpp \
				rb_set.cpp \
				rb_map_iterator.cpp \
				rb_set_iterator.cpp \
				rb_map_reverse_iterator.cpp \
				rb_set_reverse_iterator.cpp \
				map.cpp \
				set.cpp


OBJ_FT_DIR		=	./ft_builds
OBJ_STD_DIR		=	./std_builds
OBJ_FT			=	$(patsubst %.cpp, $(OBJ_FT_DIR)/%.o, $(SRC))
OBJ_STD			=	$(patsubst %.cpp, $(OBJ_STD_DIR)/%.o, $(SRC))
TEST_FT_OBJ		=	$(patsubst %.cpp, $(OBJ_FT_DIR)/%.o, $(TEST_SRC))
TEST_STD_OBJ	=	$(patsubst %.cpp, $(OBJ_STD_DIR)/%.o, $(TEST_SRC))


INCD_DIR		=	-I ./ \
					-I ./containers \
					-I ./iterators \
					-I ./others \
					-I ./rb_tree \
					-I ./tests
INCD			=	normal_iterator.hpp reverse_iterator.hpp \
					type_traits.hpp algorithm.hpp vector.hpp \
					stack.hpp rb_node.hpp rb_iterator.hpp \
					rb_tree.hpp functional.hpp map.hpp set.hpp

#______________________________________//_______________________________________
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INCD_DIR)

NAME_FT			=	ft_containers
NAME_STD		=	std_containers
TEST_FT			=	ft_test
TEST_STD		=	std_test

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

RM		=	rm -rf

CC		=	c++
#______________________________________//_______________________________________
all: $(NAME_FT) $(NAME_STD)
	for number in 1 2 3 4 5; do ./std_containers; done
	for number in 1 2 3 4 5; do ./ft_containers; done
	awk '{($$1 == "./ft_containers")? ft += $$3: std += $$3;} END {print ft/std;}' log_time

test: $(TEST_FT) $(TEST_STD)

$(NAME_FT):		$(OBJ_FT)
	$(CC) $(CFLAGS) $(OBJ_FT) $(INCD_DIR) -o $(NAME_FT)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(NAME_FT) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(NAME_STD):	$(OBJ_STD)
	$(CC) $(CFLAGS) $(OBJ_STD) $(INCD_DIR) -o $(NAME_STD)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(NAME_STD) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_FT):	$(TEST_FT_OBJ)
	$(CC) $(CFLAGS) $(TEST_FT_OBJ) $(INCD_DIR) -o $(TEST_FT)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_FT) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_STD):	$(TEST_STD_OBJ)
	$(CC) $(CFLAGS) $(TEST_STD_OBJ) $(INCD_DIR) -o $(TEST_STD)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_STD) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(OBJ_FT_DIR)/%.o:	%.cpp $(INCD)
	mkdir -p $(OBJ_FT_DIR)
	$(CC) -c -o $@ $(CFLAGS) $(INCD_DIR) $<

$(OBJ_STD_DIR)/%.o:	%.cpp $(INCD)
	mkdir -p $(OBJ_STD_DIR)
	$(CC) -c -o $@ $(CFLAGS) -D STD $(INCD_DIR) $<
#______________________________________//_______________________________________
clean:
	$(RM) $(OBJ_FT_DIR) $(OBJ_STD_DIR)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o Deletados         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean
	$(RM) $(NAME_FT) $(NAME_STD) $(TEST_FT) $(TEST_STD)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|            exect Deletado            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"
#______________________________________//_______________________________________

re:			fclean all

git:
	@git add .
	@git status
	@git commit -m "$m"

.PHONY:		all clean fclean re git
