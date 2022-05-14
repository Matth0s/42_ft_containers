# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 02:30:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/05/14 04:36:40 by mmoreira         ###   ########.fr        #
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


OBJ_DIR			=	./builds
OBJ				=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

TEST_OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TEST_SRC))


INCD_DIR		=	-I ./ \
					-I ./containers \
					-I ./iterators \
					-I ./others \
					-I ./rb_tree \
					-I ./tests
INCD			=	normal_iterator.hpp reverse_iterator.hpp \
					type_traits.hpp algorithm.hpp vector.hpp \
					stack.hpp rb_node.hpp rb_iterator.hpp \
					rb_tree.hpp
#______________________________________//_______________________________________
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INCD_DIR)

FT_NAME			=	ft_containers
STD_NAME		=	std_containers

FT_TEST			=	ft_test
STD_TEST		=	std_test

CFLAGS	=
override CFLAGS	+=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

RM		=	rm -rf

CC		=	c++
#______________________________________//_______________________________________
all: $(FT_NAME) $(STD_NAME)

$(FT_NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCD_DIR) -o $(FT_NAME)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(FT_NAME) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(STD_NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCD_DIR) -o $(STD_NAME)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(STD_NAME) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(FT_TEST):	$(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(INCD_DIR) -o $(FT_TEST)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(STD_TEST):	$(TEST_OBJ)
	$(CC) $(CFLAGS) $(TEST_OBJ) $(INCD_DIR) -o $(STD_TEST)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(OBJ_DIR)/%.o:	%.cpp $(INCD)
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $(CFLAGS) $(INCD_DIR) $<
#______________________________________//_______________________________________
clean:
	$(RM) $(OBJ_DIR)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|        Arquivos .o Deletados         |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

fclean:		clean
	$(RM) $(FT_NAME) $(STD_NAME) $(FT_TEST) $(STD_TEST)
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
