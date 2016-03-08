# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcowle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/08 16:38:35 by kcowle            #+#    #+#              #
#    Updated: 2016/03/08 16:48:00 by kcowle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -c ft_putchar.c ft_swap.c ft_putstr.c ft_strcmp.c ft_strlen.c
ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strcmp.o ft_strlen.o
rm *.o
