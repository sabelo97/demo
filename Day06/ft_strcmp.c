/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 10:24:29 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/08 11:19:09 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return 0;
		}
		s1++;
		s2++;
	}
	if (s1 < s2)
	{
		return (-1);
	}
	else
	{
		return (+1);
	}
}

int main()
{
	char str1[] = "hoooooooooooo";
	char str2[] = "bh";
	ft_strcmp(str1, str2);
	
	printf("%d", ft_strcmp(str2, str1));
	return 0;
}
