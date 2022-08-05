/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:05:37 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:05:39 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c > 255)
		c %= 256;
	while (*s)
	{
		i++;
		s++;
	}
	while (i-- > 0)
	{
		if (*s-- == (char) c)
			return ((char *)(s + 1));
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
