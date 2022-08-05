/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:01:03 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:01:04 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*copy;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + 1;
	copy = malloc(size);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy, s1, size);
	return (copy);
}
