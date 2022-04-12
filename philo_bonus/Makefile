# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:04:18 by mfagri            #+#    #+#              #
#    Updated: 2022/04/11 23:03:19 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC = philo_bonus.h

SRC = philo_bonus.c \
		utils_bonus.c\
		init_data_bonus.c\
		devil.c\
		
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(INC) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)