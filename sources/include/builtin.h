/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slorimer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:09:13 by slorimer          #+#    #+#             */
/*   Updated: 2022/04/02 14:09:14 by slorimer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <logic.h>

# define ARG_ERROR "too many arguments"
# define NUM_ERROR "numeric argument required"

int		ft_pwd(void);
int		ft_cd(char **argv);
int		ft_env(char **argv);
int		ft_exit(char **argv);
int		ft_echo(char **argv);
int		ft_unset(char **argv);
int		ft_export(char **argv);

void	output_prompts(void);
void	*freedom(char ***arr);
void	err_msg(char *str, int option);
char	*get_str(char **envp, char *reference);

#endif
