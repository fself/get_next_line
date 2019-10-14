/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:43:17 by fself             #+#    #+#             */
/*   Updated: 2019/09/20 15:56:08 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	int		needle_len;

	ptr = (char*)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return (ptr);
	while (*ptr)
	{
		if (*ptr == *needle)
		{
			if (ft_strncmp(needle, ptr, needle_len) == 0)
				return (ptr);
		}
		ptr++;
	}
	return (NULL);
}
