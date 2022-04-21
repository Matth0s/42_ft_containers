# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 02:30:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/04/21 00:37:58 by mmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______________________________________//_______________________________________
SRC_DIR	=	./ ./tests
SRC		=	main.cpp
VEC_ITER=	iterator.cpp
REV_ITER=	reverse_iterator.cpp
TYPE_TRAITS= type_traits.cpp
VECTOR	=	vector.cpp

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
VEC_ITER_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(VEC_ITER))
REV_ITER_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(REV_ITER))
TYPE_TRAITS_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TYPE_TRAITS))
VECTOR_OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(VECTOR))

INCD_DIR=	-I ./ \
			-I ./containers \
			-I ./iterators \
			-I ./others
VEC_ITER_INCD	= vector_iterator.hpp
REV_ITER_INCD	= reverse_iterator.hpp
TYPE_TRAITS_INCD= type_traits.hpp
VECTOR_INCD		= vector.hpp
INCD	= $(VEC_ITER_INCD) $(REV_ITER_INCD) $(TYPE_TRAITS_INCD) $(VECTOR_INCD)

#______________________________________//_______________________________________
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INCD_DIR)

FT_NAME			=	ft_containers
STD_NAME		=	std_containers

TEST_VEC_ITER	=	veciter
TEST_REV_ITER	=	reviter
TEST_TYPE_TRAITS=	typetraits
TEST_VECTOR		=	vector

ALL_TEST= $(TEST_VEC_ITER) $(TEST_REV_ITER) $(TEST_TYPE_TRAITS) $(TEST_VECTOR)

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

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
	@./veciter
	@echo "******************************"
	@echo "****Reverse Iterator Testes****"
	@./reviter
	@echo "*******************************"
	@echo "**********Type Traits**********"
	@./typetraits
	@echo "*******************************"
	@echo "*********Vector Testes*********"
	@./vector
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

$(TEST_VECTOR):	$(VECTOR_OBJ)
	$(CC) $(CFLAGS) $(VECTOR_OBJ) $(INCD_DIR) -o $(TEST_VECTOR)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             $(TEST_VECTOR) Criado"
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
	$(RM) $(NAME) $(ALL_TEST)
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
