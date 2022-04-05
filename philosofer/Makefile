# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:04:18 by mfagri            #+#    #+#              #
#    Updated: 2022/04/05 17:58:47 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc 
CFLAGS = -Wall -Wextra -Werror
INC = philo.h

SRC = philo.c \
		utils.c\
		init_data.c\
		init_philos.c\
		
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(INC) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)