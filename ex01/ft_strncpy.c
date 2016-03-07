/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:59:59 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/07 14:31:40 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
	int index;

	index = 0;
	while (index <= n)
	{
		dest[index] = src[index];
		write(1, &dest, 1);
		index++;
	}
	return 0;
}
