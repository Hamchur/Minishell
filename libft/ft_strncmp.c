/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:04:50 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:04:51 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t stop)
{
	while ((*str1 || *str2) && stop--)
		if (*str1++ != *str2++)
			return (*(str1 - 1) - *(str2 - 1));
	return (0);
}
