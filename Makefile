# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoreira <mmoreira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 02:30:49 by mmoreira          #+#    #+#              #
#    Updated: 2022/05/24 23:31:43 by mmoreira         ###   ########.fr        #
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
all: $(NAME_FT) $(NAME_STD) $(TEST_FT) $(TEST_STD)

vector: all
	./std_test vector
	./ft_test vector
	./std_containers vector
	./ft_containers vector
	@awk '{\
	if ($$1 == "./ft_containers") if($$2 == "vector") ft += $$4;\
	if ($$1 == "./std_containers") if($$2 == "vector") std += $$4;\
	} END {print "ft é   " ft/std "x   mais lendo que std"}' log_time

stack: all
	./std_test stack
	./ft_test stack
	./std_containers stack
	./ft_containers stack
	@awk '{\
	if ($$1 == "./ft_containers") if($$2 == "stack") ft += $$4;\
	if ($$1 == "./std_containers") if($$2 == "stack") std += $$4;\
	} END {print "ft é   " ft/std "x   mais lendo que std"}' log_time

map: all
	./std_test map
	./ft_test map
	./std_containers map
	./ft_containers map
	@awk '{\
	if ($$1 == "./ft_containers") if($$2 == "map") ft += $$4;\
	if ($$1 == "./std_containers") if($$2 == "map") std += $$4;\
	} END {print "ft é   " ft/std "x   mais lendo que std"}' log_time

set: all
	./std_test set
	./ft_test set
	./std_containers set
	./ft_containers set
	@awk '{\
	if ($$1 == "./ft_containers") if($$2 == "set") ft += $$4;\
	if ($$1 == "./std_containers") if($$2 == "set") std += $$4;\
	} END {print "ft é   " ft/std "x   mais lendo que std"}' log_time

$(NAME_FT):		$(OBJ_FT)
	$(CC) $(CFLAGS) $(OBJ_FT) $(INCD_DIR) -o $(NAME_FT)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|       $(NAME_FT) Criado"
	@echo "\\ ************************************ /"
	@echo "\033[0m"

$(NAME_STD):	$(OBJ_STD)
	$(CC) $(CFLAGS) $(OBJ_STD) $(INCD_DIR) -o $(NAME_STD)
	@echo "\033[1;32m"
	@echo "/ ************************************ \\"
	@echo "|       $(NAME_STD) Criado"
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
