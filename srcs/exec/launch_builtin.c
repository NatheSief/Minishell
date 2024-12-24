/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:11 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 13:54:24 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_builtin(t_shell *master, t_cmd *cmd, int save_stdout)
{
	if (!ft_strncmp("echo", cmd->cmd[0], INT_MAX))
		master->ret_value = ft_echo(master, cmd);
	else if (!ft_strncmp("cd", cmd->cmd[0], INT_MAX))
		master->ret_value = ft_cd(master, cmd);
	else if (!ft_strncmp("pwd", cmd->cmd[0], INT_MAX))
		master->ret_value = ft_pwd(master);
	else if (!ft_strncmp("export", cmd->cmd[0], INT_MAX))
		master->ret_value = ft_export(master, cmd);
	else if (!ft_strncmp("unset", cmd->cmd[0], INT_MAX))
		master->ret_value = ft_unset(master, cmd);
	else if (!ft_strncmp("env", cmd->cmd[0], INT_MAX))
		master->ret_value = ft_env(master);
	else if (!ft_strncmp("exit", cmd->cmd[0], INT_MAX))
	{
		if (cmd->output >= 0)
		{
			dup2(save_stdout, 1);
			close(save_stdout);
		}
		ft_exit(master, cmd);
	}
}

int	launch_builtin(t_shell *master, t_cmd *cmd)
{
	int	save_stdout;

	save_stdout = -1;
	if (cmd->output >= 0)
	{
		save_stdout = dup(1);
		dup2(cmd->output, 1);
	}
	exec_builtin(master, cmd, save_stdout);
	if (cmd->output >= 0)
	{
		dup2(save_stdout, 1);
		close (save_stdout);
	}
	return (0);
}
