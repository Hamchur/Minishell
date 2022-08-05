/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:13:33 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:13:35 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

char	*get_quotes_content(char *str)
{
	char	*content;
	char	quote;
	int		i;

	i = 0;
	quote = *str++;
	while (str[i] && str[i] != quote)
		i++;
	content = ft_strndup(str, i);
	if (!content)
		raise_error(MEMORY_ERROR, NULL);
	return (content);
}

char	*get_dollar(char *str)
{
	char	*dollar;
	int		i;

	i = 1;
	if (str[i] == '?')
		dollar = ft_strdup("?");
	else
	{
		while (!ft_strchr(" <>$'\"\t\v\0", str[i]))
			i++;
		dollar = ft_strndup(&str[1], i - 1);
	}
	if (!dollar)
		raise_error(MEMORY_ERROR, NULL);
	return (dollar);
}

char	*get_dollar_for_expand(char *str)
{
	char	*dollar;
	int		i;

	i = 1;
	if (str[i] == '?')
		dollar = ft_strdup("?");
	else
	{
		while (!ft_strchr(" :<>$'\"\t\v\0", str[i]))
			i++;
		dollar = ft_strndup(&str[1], i - 1);
	}
	if (!dollar)
		raise_error(MEMORY_ERROR, NULL);
	return (dollar);
}

char	*get_redirect(char *str)
{
	char	*redirect;
	int		i;

	redirect = NULL;
	i = skip_redirect(str);
	return (redirect);
}

char	*get_argument(char *str)
{
	char	*argument;
	int		i;

	i = skip_argument(str);
	argument = ft_strndup(str, i);
	if (!argument)
		raise_error(MEMORY_ERROR, NULL);
	return (argument);
}
