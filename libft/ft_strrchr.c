/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:37:32 by fself             #+#    #+#             */
/*   Updated: 2019/09/20 15:40:39 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		s_len;

	s_len = ft_strlen(s);
	ptr = (char*)s + s_len - 1;
	if (c == '\0')
	{
		ptr++;
		return (ptr);
	}
	while (s_len != 0)
	{
		if (*ptr == c)
		{
			return (ptr);
		}
		s_len--;
		ptr--;
	}
	return (NULL);
}
