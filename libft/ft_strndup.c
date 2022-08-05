/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:05:01 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:05:03 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*new;
	size_t	len;
	size_t	index;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (n > len)
		n = len;
	new = malloc(sizeof (char) * (n + 1));
	if (!new)
		return (NULL);
	index = 0;
	while (index < n)
	{
		new[index] = s1[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}
