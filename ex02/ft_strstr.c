/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 12:10:14 by kcowle            #+#    #+#             */
/*   Updated: 2016/03/07 16:38:32 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strstr(char *str, char *to_find)
{
    int index;
    int find;

    index = 0;
    while (str[index] != '\0')
    {
        find = 0;
        while (str[index + i] == to_find[i])
        {
            i++;
            if (to_find[i] == '\0')
            {
                return (to_find);
            }
        }
        index++;
    }
    return 0;
}
