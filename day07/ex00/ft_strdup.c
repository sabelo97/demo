/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 08:18:24 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/09 09:29:59 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int index;
	char *dest;
   
	dest = malloc(sizeof(src) + 1);
	index = 0;

	if (src[index] == '\0')
	{
		return (0); 
	}

	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	return (dest[index]);
}
