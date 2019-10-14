/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:41:38 by fself             #+#    #+#             */
/*   Updated: 2019/09/20 15:35:13 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	unsigned char *dst;
	unsigned char *src;

	if (num == 0 || destination == source)
		return (destination);
	dst = (unsigned char*)destination;
	src = (unsigned char*)source;
	while (num-- > 0)
	{
		dst[num] = src[num];
	}
	return (destination);
}
