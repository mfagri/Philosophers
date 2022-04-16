# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 23:09:16 by mfagri            #+#    #+#              #
#    Updated: 2022/04/16 23:12:04 by mfagri           ###   ########.fr        #
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

re: fclean all