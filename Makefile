# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 02:30:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/04/18 14:00:41 by mmoreira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______________________________________//_______________________________________
SRC_DIR	=	./ ./tests
SRC		=	main.cpp
VEC_ITER=	iterator.cpp
REV_ITER=	reverse_iterator.cpp

OBJ_DIR	=	./builds
OBJ		=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))
VEC_ITER_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(VEC_ITER))
REV_ITER_OBJ	=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(REV_ITER))

INCD_DIR=	-I ./ \
			-I ./containers \
			-I ./iterators
VEC_ITER_INCD	= vector_iterator.hpp
REV_ITER_INCD	= reverse_iterator.hpp
INCD	=

#______________________________________//_______________________________________
vpath %.cpp $(SRC_DIR)
vpath %.hpp $(INCD_DIR)

NAME	=	exect
TEST_VEC_ITER = veciter
TEST_REV_ITER = reviter

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

RM		=	rm -rf

CC		=	c++
#______________________________________//_______________________________________
all:			$(NAME)

teste:			$(TEST_VEC_ITER) $(TEST_REV_ITER)
	@echo "****Vector Iterator Testes****"
	@./veciter
	@echo "******************************"
	@echo "****Reverse Iterator Testes****"
	@./reviter
	@echo "*******************************"

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(INCD_DIR) -o $(NAME)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             exect Criado             |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_VEC_ITER):	$(VEC_ITER_OBJ)
	$(CC) $(CFLAGS) $(VEC_ITER_OBJ) $(INCD_DIR) -o $(TEST_VEC_ITER)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             exect Criado             |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(TEST_REV_ITER):	$(REV_ITER_OBJ)
	$(CC) $(CFLAGS) $(REV_ITER_OBJ) $(INCD_DIR) -o $(TEST_REV_ITER)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|             exect Criado             |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(OBJ_DIR)/%.o:	%.cpp $(REV_ITER_INCD) $(VEC_ITER_INCD)
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
	$(RM) $(NAME) $(TEST_VEC_ITER) $(TEST_REV_ITER)
	@echo "\033[1;31m"
	@echo "/ ************************************ \\"
	@echo "|            exect Deletado            |"
	@echo "\\ ************************************ /"
	@echo "\033[0m"
#______________________________________//_______________________________________

re:			fclean all

.PHONY:		all clean fclean re
