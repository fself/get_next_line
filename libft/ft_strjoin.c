/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 22:00:08 by fself             #+#    #+#             */
/*   Updated: 2019/09/20 22:04:27 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_to;
	int		i;

	if (s1 && s2)
	{
		str_to = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str_to)
		{
			i = 0;
			while (*s1)
			{
				str_to[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				str_to[i++] = *s2;
				s2++;
			}
			str_to[i] = '\0';
			return (str_to);
		}
	}
	return (NULL);
}
