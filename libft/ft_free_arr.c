/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:51:36 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 18:51:38 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_arr(char ***arr)
{
	char	**temp;
	int		index;

	index = 0;
	temp = *arr;
	if (!temp)
		return (temp);
	while (temp[index])
	{
		free(temp[index]);
		temp[index] = NULL;
		index++;
	}
	free(temp);
	temp = NULL;
	return (NULL);
}
