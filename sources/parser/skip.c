/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:14:12 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:14:13 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

int	skip_argument(char *str)
{
	int	i;

	i = 0;
	while (!ft_strchr(" <>|\t\v\0", str[i]))
	{
		if (str[i] == '\'' || str[i] == '"')
			i += skip_quotes(&str[i]);
		i++;
	}
	return (i);
}

int	skip_quotes(char *str)
{
	char	quote;
	int		i;

	i = 0;
	quote = str[i++];
	while (str[i] && str[i] != quote)
		i++;
	if (str[i] == '\0')
		raise_error(NEWL_ERROR, NULL);
	return (i);
}

int	skip_redirect(char *str)
{
	int		i;

	i = 0;
	if (!str[i])
		raise_error(NEWL_ERROR, NULL);
	else if (ft_strchr("|<>", str[i]))
		raise_error(TOKEN_ERROR, &str[i]);
	else
	{
		while (str[i] && !ft_strchr(" <>|\t\v", str[i]))
		{
			if (str[i] == '\'' || str[i] == '"')
				i += skip_quotes(&str[i]);
			i++;
		}
	}
	return (i);
}
