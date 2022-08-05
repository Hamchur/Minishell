/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:06:49 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:06:51 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*combine(char *ret, char *divv, char **split)
{
	char	*temp;

	temp = ret;
	if (!temp)
		return (NULL);
	ret = ft_strjoin(ret, divv);
	free(temp);
	temp = ret;
	if (!temp)
		return (NULL);
	ret = ft_strjoin(ret, *(split + 1));
	free(temp);
	return (ret);
}

char	*ft_unite(char **split, char div)
{
	char	*ret;
	char	*divv;

	if (!split || !*split)
		return (NULL);
	divv = ft_calloc(2, 1);
	if (!divv)
		return (NULL);
	divv[0] = div;
	ret = ft_strdup(*split);
	while (*(split + 1))
	{
		ret = combine(ret, divv, split);
		if (!ret)
			return (NULL);
		split++;
	}
	free(divv);
	return (ret);
}
