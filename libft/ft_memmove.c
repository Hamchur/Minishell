/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:58:31 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 18:58:34 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dst;
	s = src;
	if (d == s)
		return (dst);
	if (dst > src)
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len > 0)
		{
			*d-- = *s--;
			len--;
		}
	}
	while (len > 0)
	{
		*d++ = *s++;
		len--;
	}
	return (dst);
}
