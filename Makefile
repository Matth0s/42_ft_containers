# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 02:30:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/05/12 19:20:41 by mmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______________________________________//_______________________________________
SRC_DIR		=	./ ./tests
SRC			=	main.cpp
VEC_ITER	=	iterator.cpp
REV_ITER	=	reverse_iterator.cpp
TYPE_TRAITS	=	type_traits.cpp
UTILITY		=	utility.cpp
ALGORITHM	=	algorithm.cpp
VECTOR		=	vector.cpp
STACK		=	stack.cpp
RBTREE		=	rb_tree.cpp

OBJ_DIR			=	./builds
OBJ				=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
VEC_ITER_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(VEC_ITER))
REV_ITER_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(REV_ITER))
TYPE_TRAITS_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TYPE_TRAITS))
UTILITY_OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(UTILITY))
ALGORITHM_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(ALGORITHM))
VECTOR_OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(VECTOR))
STACK_OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(STACK))
RBTREE_OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(RBTREE))

INCD_DIR		=	-I ./ \
					-I ./containers \
					-I ./iterators \
					-I ./others \
					-I ./rb_tree
INCD			=	vector_iterator.hpp reverse_iterator.hpp \
					type_traits.hpp algorithm.hpp vector.hpp \
					stack.hpp rb_node.hpp rb_iterator.hpp \
					rb_tree.hpp
#______________________________________//_______________________________________
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INCD_DIR)

FT_NAME			=	ft_containers
STD_NAME		=	std_containers

TEST_VEC_ITER	=	veciter
TEST_REV_ITER	=	reviter
TEST_TYPE_TRAITS=	typetraits
TEST_UTILITY	=	utility
TEST_ALGORITHM	=	algorithm
TEST_VECTOR		=	vector
TEST_STACK		=	stack
TEST_RBTREE		=	rbtree

ALL_TEST	= $(TEST_VEC_ITER) $(TEST_REV_ITER) \
			$(TEST_TYPE_TRAITS) $(TEST_UTILITY) \
			$(TEST_ALGORITHM) $(TEST_VECTOR) \
			$(TEST_STACK) $(TEST_RBTREE)

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3 #-fsanitize=address

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

teste:			$(ALL_TEST)
	@echo "****Vector Iterator Testes****"
	@./$(TEST_VEC_ITER)
	@echo "******************************"
	@echo "****Reverse Iterator Testes****"
	@./$(TEST_REV_ITER)
	@echo "*******************************"
	@echo "**********Type Traits**********"
	@./$(TEST_TYPE_TRAITS)
	@echo "*******************************"
	@echo "************Utility************"
	@./$(TEST_UTILITY)
	@echo "*******************************"
	@echo "***********Algorithm***********"
	@./$(TEST_ALGORITHM)
	@echo "*******************************"
	@echo "*********Vector Testes*********"
	@./$(TEST_VECTOR)
	@echo "*******************************"
	@echo "**********Stack Testes*********"
	@./$(TEST_STACK)
	@echo "*******************************"
	@echo "*********RB_Tree Testes********"
	@./$(TEST_RBTREE)
	@echo "*******************************"

$(TEST_VEC_ITER):	$(VEC_ITER_OBJ)
	$(CC) $(CFLAGS) $(VEC_ITER_OBJ) $(INCD_DIR) -o $(TEST_VEC_ITER)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_VEC_ITER) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_REV_ITER):	$(REV_ITER_OBJ)
	$(CC) $(CFLAGS) $(REV_ITER_OBJ) $(INCD_DIR) -o $(TEST_REV_ITER)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_REV_ITER) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_TYPE_TRAITS):	$(TYPE_TRAITS_OBJ)
	$(CC) $(CFLAGS) $(TYPE_TRAITS_OBJ) $(INCD_DIR) -o $(TEST_TYPE_TRAITS)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_TYPE_TRAITS) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_UTILITY):	$(UTILITY_OBJ)
	$(CC) $(CFLAGS) $(UTILITY_OBJ) $(INCD_DIR) -o $(TEST_UTILITY)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_UTILITY) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_ALGORITHM):	$(ALGORITHM_OBJ)
	$(CC) $(CFLAGS) $(ALGORITHM_OBJ) $(INCD_DIR) -o $(TEST_ALGORITHM)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_ALGORITHM) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_VECTOR):	$(VECTOR_OBJ)
	$(CC) $(CFLAGS) $(VECTOR_OBJ) $(INCD_DIR) -o $(TEST_VECTOR)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_VECTOR) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_STACK):	$(STACK_OBJ)
	$(CC) $(CFLAGS) $(STACK_OBJ) $(INCD_DIR) -o $(TEST_STACK)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_STACK) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_RBTREE):	$(RBTREE_OBJ)
	$(CC) $(CFLAGS) $(RBTREE_OBJ) $(INCD_DIR) -o $(TEST_RBTREE)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_RBTREE) Criado"
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
	$(RM) $(FT_NAME) $(STD_NAME) $(ALL_TEST)
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
