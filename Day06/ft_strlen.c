/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 14:40:45 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/08 14:45:34 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

int		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	if (n < 10)
	{
		ft_putchar(n % 10 + '0');
	}
	return (n);
}

int ft_strlen(char *str)
{
	int index;
	char result;
	
	index = 0;
	
	while(str[index] != '\0')
	{
		index++;
	}
	result = index;
	ft_putnbr(index);
	return 0;
}
