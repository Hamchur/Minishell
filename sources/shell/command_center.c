/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamchur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:17:07 by hamchur           #+#    #+#             */
/*   Updated: 2022/04/01 19:17:08 by hamchur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_msg(int *stat)
{
	int	status;

	status = *stat;
	if (WIFSIGNALED(status) && WTERMSIG(status) == 3)
	{
		ft_putstr_fd("Quit\n", STDOUT_FILENO);
		g_info.last_prcs = SIG_BCK;
	}
	else if (WIFSIGNALED(status) && WTERMSIG(status) == 2)
	{
		write(STDOUT_FILENO, "\n", 1);
		g_info.last_prcs = SIG_END;
		g_info.sig = 0;
	}
	else if (!WIFSIGNALED(status))
		g_info.last_prcs = WEXITSTATUS(status);
}

int	get_exit(t_command *commands)
{
	int	status;

	status = 0;
	while (commands)
	{
		if (commands->pid > 0)
		{
			waitpid(commands->pid, &status, 0);
			if (status == 127)
				g_info.last_prcs = 127;
			else if (WIFEXITED(status))
				g_info.last_prcs = WEXITSTATUS(status);
			else
				print_msg(&status);
		}
		commands = commands->next;
	}
	return (0);
}

static int	get_fd(t_command *command)
{
	int			ret;
	t_command	*temp;

	ret = 0;
	temp = command;
	while (temp)
	{
		temp->num = ret;
		ret++;
		temp = temp->next;
	}
	ret = 0;
	while (!ret && command)
	{
		redirect(command->rdrct, command->fd_redirs, command);
		if (command->fd_redirs[0] == SIG_END)
		{
			ret = 1;
			continue ;
		}
		command = command->next;
	}
	return (ret);
}

int	command_center(char *input, char ***envp)
{
	int			ret;

	g_info.commands = parse_string(input);
	if (g_info.commands)
	{
		if (!get_fd(g_info.commands))
		{
			ret = pipex(g_info.commands);
			if (ret == 1)
				g_info.last_prcs = 1;
			else if (ret)
				g_info.last_prcs = 127;
		}
		dup2(g_info.std_fd[0], STDIN_FILENO);
		dup2(g_info.std_fd[1], STDOUT_FILENO);
	}
	get_exit(g_info.commands);
	free_command(g_info.commands);
	*envp = g_info.env;
	errno = 0;
	g_info.error = 0;
	return (0);
}
