/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 07:17:49 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/08 07:21:31 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2, unsigned int n)
{
	int index;

	index = 0;
	while (*s1 == *s2 && index <= n)
	{
		if (*s1 == '\0')
	{
		return 0;
	}
	s1++;
	s2++;
	index++;
	}
	
	if (*(unsigned char *)s1 < *(unsigned char *)s2)
	{
		return -1;
	}
	else
	{
		return +1;
	}
}
