/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:58:08 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 18:58:09 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*str1;
	unsigned const char	*str2;

	str1 = s1;
	str2 = s2;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*str1 != *str2)
				return ((int)(*str1 - *str2));
			str1++;
			str2++;
			n--;
		}
	}
	return (0);
}
