/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:57:43 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 18:57:44 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		b;
	unsigned char		*d;
	unsigned const char	*s;

	b = c;
	d = dst;
	s = src;
	if (c > 255)
		c %= 256;
	while (n != 0)
	{
		*d++ = *s++;
		if (*(d - 1) == b)
			return (d);
		n--;
	}
	return (NULL);
}
