# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfagri <mfagri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 18:04:18 by mfagri            #+#    #+#              #
#    Updated: 2022/04/16 23:13:03 by mfagri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BONUS = philo_bonus

CC = cc 
CFLAGS = -Wall -Wextra -Werror

INCB = philo_bonus.h

SRCB = philo_bonus.c \
		utils_bonus.c\
		init_data_bonus.c\
		init_philos_bonus.c\
		

		
OBJB = $(SRCB:.c=.o)


	
bonus: $(BONUS)

$(BONUS):$(OBJB) $(INCB) clean
	$(CC) $(CFLAGS) $(SRCB) -o $(BONUS)

clean:
	@rm -rf $(OBJB)
fclean: clean
	@rm -rf $(BONUS)

re: fclean bonus