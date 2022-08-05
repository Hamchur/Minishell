/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:00:51 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:00:52 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(char *str, char *set)
{
	char	*new;
	int		i;

	if (!str || !set)
		return (NULL);
	i = 0;
	while (str[i] && !ft_strchr(set, str[i]))
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && !ft_strchr(set, str[i]))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
