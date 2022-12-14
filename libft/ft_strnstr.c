/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:05:14 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:05:16 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	h;

	h = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && h < len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (haystack[i] && needle[i] && haystack[i] == needle[i])
				i++;
			if (i + h > len)
				return (NULL);
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		h++;
	}
	return (NULL);
}
