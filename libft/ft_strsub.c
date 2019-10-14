/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:48:23 by fself             #+#    #+#             */
/*   Updated: 2019/09/20 21:51:47 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	if (s)
	{
		substr = ft_strnew(len);
		if (substr)
		{
			i = start;
			j = 0;
			while (j < len)
			{
				substr[j] = s[i];
				i++;
				j++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (NULL);
}
