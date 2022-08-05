/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:08:48 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:08:50 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtin.h>

static void	ft_putstr(char *str, int flag)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	if (flag == 1)
		write(STDOUT_FILENO, " ", 1);
	if (flag == 2)
		write(STDOUT_FILENO, "\n", 1);
}

static void	ft_cycle(int flag, int index, char **argv)
{
	while (argv[index])
	{
		if (!argv[index + 1])
			ft_putstr(argv[index], flag);
		else
			ft_putstr(argv[index], 1);
		index++;
	}
}

int	ft_echo(char **argv)
{
	int	argc;

	argc = 0;
	while (argv[argc])
		argc++;
	if (argc < 2)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	if (argc == 2 && !ft_strncmp(argv[1], "-n", 3))
		return (0);
	if (argc > 2 && !ft_strncmp(argv[1], "-n", 3))
		ft_cycle(0, 2, argv);
	else
		ft_cycle(2, 1, argv);
	return (0);
}
