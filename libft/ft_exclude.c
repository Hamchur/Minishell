/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exclude.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:51:21 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 18:51:23 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exclude(char **array, char *str)
{
	int	index_str;
	int	index_null;

	index_null = 0;
	index_str = 0;
	while (array[index_null])
	{
		if (!ft_strncmp(array[index_null], str, ft_strlen(str)) && !index_str)
			index_str = index_null;
		index_null++;
	}
	if (index_str)
	{
		free(array[index_str]);
		while (index_str < index_null)
		{
			array[index_str] = array[index_str + 1];
			index_str++;
		}
	}
}
