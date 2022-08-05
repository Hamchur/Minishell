/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:48:38 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 18:48:49 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*freedom(char ***arr)
{
	char	**temp;

	temp = *arr;
	while (temp)
	{
		free(*temp);
		temp += sizeof(char *);
	}
	free(*arr);
	return (NULL);
}

char	**ft_arrdup(char **arr)
{
	char	**temp;
	int		index;
	int		counter;

	index = 0;
	counter = 0;
	while (arr[counter])
		counter++;
	temp = ft_calloc(counter + 1, sizeof(char *));
	if (!temp)
		return (NULL);
	while (index < counter)
	{
		temp[index] = ft_strdup(arr[index]);
		if (!temp[index])
			return (freedom(&temp));
		index++;
	}
	return (temp);
}
