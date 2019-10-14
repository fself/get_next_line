/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:19:49 by fself             #+#    #+#             */
/*   Updated: 2019/09/18 16:29:44 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	unsigned char	i;
	unsigned char	j;

	i = 0;
	while (dst[i] != '\0')
		++i;
	j = 0;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		++j;
	}
	dst[i] = '\0';
	return (dst);
}
