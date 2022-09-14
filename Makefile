# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 20:13:55 by bchelste          #+#    #+#              #
#    Updated: 2022/09/15 00:30:49 by bchelste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	n-puzzle
INC_DIR		=	includes
SRC_DIR		=	srcs
CC			=	clang++

SRCS		=	$(SRC_DIR)/main.cpp \
				$(SRC_DIR)/Puzzle.cpp \
				$(SRC_DIR)/PuzzleData.cpp 
				
OBJS		=	$(SRCS:.cpp=.o)

INC			=	-I$(INC_DIR)

HEAD		=	$(INC_DIR)/Puzzle.hpp \
				$(INC_DIR)/PuzzleData.hpp

CFLAGS		=	-Wextra -Werror -Wall $(INC)

OPTFLAGS	=	-O0

MAKE		=	make

RM			=	rm -rf

.PHONY: all clean fclean re

all:
	@$(MAKE) $(NAME) -j 4

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OPTFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)
	$(RM) puzzle3.puzzle

re: fclean all

gen3s:
	python3 ./additional/npuzzle_gen.py 3 -s > puzzle3.puzzle

gen3u:
	python3 ./additional/npuzzle_gen.py 3 -u > puzzle3.puzzle

%.o:%.cpp $(HEAD)
	$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@

