/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slorimer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:09:22 by slorimer          #+#    #+#             */
/*   Updated: 2022/04/02 14:09:23 by slorimer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# include <libft.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <err.h>
# include <stdbool.h>
# include <inttypes.h>

typedef struct s_command
{
	int		fd_redirs[2];
	int		num;
	char	*file;
	char	*name;
	char	**argv;
	char	**rdrct;
	pid_t	pid;
	void	*next;
}			t_command;

typedef struct s_info
{
	uint8_t		sig;
	uint8_t		error;
	uint8_t		last_prcs;
	int32_t		std_fd[2];
	int32_t		*filed;
	t_command	*commands;
	char		*minidir;
	char		**files;
	char		**env;
	char		**bltn;
}				t_info;

#endif
