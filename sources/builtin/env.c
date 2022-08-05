/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:09:00 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:09:02 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

int	ft_env(char **argv)
{
	int	i;

	if (argv && argv[1])
	{
		ft_putstr_fd("minishell: env: ", STDERR_FILENO);
		ft_putendl_fd(ARG_ERROR, STDERR_FILENO);
		return (1);
	}
	if (!ft_getenv(g_info.env, "PATH"))
	{
		ft_putstr_fd("minishell: env: ", STDERR_FILENO);
		ft_putendl_fd("No such file or directory", STDERR_FILENO);
		return (127);
	}
	i = 0;
	while (g_info.env && g_info.env[i])
	{
		ft_putendl_fd(g_info.env[i], STDOUT_FILENO);
		i++;
	}
	return (0);
}
