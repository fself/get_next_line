/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:26:53 by fself             #+#    #+#             */
/*   Updated: 2019/09/20 16:33:23 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	size_t	letters_left;
	size_t	needle_len;
	size_t	i;

	ptr = (char*)haystack;
	if (needle[0] == '\0')
		return (ptr);
	i = 0;
	letters_left = len;
	needle_len = (size_t)ft_strlen(needle);
	while (*ptr && letters_left >= needle_len)
	{
		if (*ptr == *needle)
		{
			if (ft_strncmp(needle, ptr, needle_len) == 0)
				return (ptr);
		}
		i++;
		letters_left--;
		ptr++;
	}
	return (NULL);
}
