/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:01:28 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:01:30 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = 0;
	d = ft_strlen(dst);
	if (d < dstsize)
		i = d;
	else
		return (dstsize + ft_strlen(src));
	while (*dst)
		dst++;
	while (src[s] != '\0' && s + i < dstsize - 1)
	{
		if (dstsize - i > 0)
		{
			*dst++ = src[s];
			s++;
		}
	}
	*dst = '\0';
	return (i + ft_strlen(src));
}
