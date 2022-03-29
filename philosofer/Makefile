# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:04:18 by mfagri            #+#    #+#              #
#    Updated: 2022/03/29 19:33:39 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c \
		utils.c\
		init_data.c\
		init_philos.c\
		
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)