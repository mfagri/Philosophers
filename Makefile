# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:04:18 by mfagri            #+#    #+#              #
#    Updated: 2022/04/16 18:17:10 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS = bonus
NAME = mandatory
CC = cc 
CFLAGS = -Wall -Wextra -Werror
INCB = philo_bonus/philo_bonus.h
INC = philo/philo.h

SRCB = philo_bonus/philo_bonus.c \
		philo_bonus/utils_bonus.c\
		philo_bonus/init_data_bonus.c\
		philo_bonus/init_philos_bonus.c\
		
SRC = philo/philo.c \
		philo/utils.c\
		philo/init_data.c\
		philo/init_philos.c\
		
OBJB = $(SRCB:.c=.o)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ) $(INC) clean
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	
bonus: $(BONUS)

$(BONUS):$(OBJB) $(INCB) clean
	$(CC) $(CFLAGS) $(SRCB) -o $(BONUS)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJB)
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

re: fclean all bonus