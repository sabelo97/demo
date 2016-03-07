/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:22:20 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/07 18:40:23 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strcmp(char *s1, char *s2)
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
    if (*(unsigned char *)s1 < *(unsigned char *)s2)
        {
            return -1;
        }
    else
        {
             return +1;
        }
}
