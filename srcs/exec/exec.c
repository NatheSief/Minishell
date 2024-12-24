/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 22:02:53 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 13:51:35 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Compare if my command is a builtin, if it is it will return 0, 
//		else it returns 1
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (1);
	if (!ft_strncmp("echo", cmd, INT_MAX))
		return (0);
	else if(!ft_strncmp("cd", cmd, INT_MAX))
		return (0);
	else if(!ft_strncmp("pwd", cmd, INT_MAX))
		return (0);
	else if(!ft_strncmp("export", cmd, INT_MAX))
		return (0);
	else if (!ft_strncmp("unset", cmd, INT_MAX))
		return (0);
	else if(!ft_strncmp("env", cmd, INT_MAX))
		return (0);
	else if(!ft_strncmp("exit", cmd, INT_MAX))
		return (0);
	return (1);
}

//	Connect the input/output of the commands together
static void	parent_process(t_cmd *cmd, int *pip)
{
	close(pip[1]);
	if (cmd->input >= 0)
		close(cmd->input);
	if (cmd->input == -2)
		cmd->input = pip[0];
	if (cmd->next_pipe != NULL && cmd->next_pipe->input == -2)
		cmd->next_pipe->input = pip[0];
	else
		close(pip[0]);
}

//	Make the fork, then if 
static int	exec_cmd(t_shell *master, t_cmd *cmd, int *pip)
{
	g_signal_pid = fork();
	if (g_signal_pid < 0)
		return (free_all(master, "PID ERROR", 1), 1);
	else if (g_signal_pid == 0)
	{
		if (cmd->cmd[0])
			child_process(master, cmd, pip);
		else
			free_all(master, NULL, 0);
	}
	else
		parent_process(cmd, pip);
	return (0);
}

static void	wait_all(t_shell *master)
{
	int		status;
	int		pid;
	int		len;
	t_cmd	*tmp;

	tmp = *master->command;
	len = ft_len_cmd(tmp);
	while (len--)
	{
		pid = waitpid(0, &status, 0);
		if (pid == g_signal_pid)
		{
			if (WIFEXITED(status))
				master->ret_value = WEXITSTATUS(status);
		}
		if (tmp->output >= 0)
			close(tmp->output);
		if (tmp->input >= 0)
			close(tmp->input);
		tmp = tmp->next_pipe;
	}
}

int	ft_exec(t_shell *master)
{
	t_cmd	*tmp;
	int		*pip;

	pip = master->fd;
	tmp = *master->command;
	if (tmp && !tmp->skipable && !tmp->next_pipe && tmp->cmd[0] \
		&& is_builtin(tmp->cmd[0]))
		return (launch_builtin(master, tmp));
	if (pipe(pip) == -1)
		return (1);
	exec_cmd(master, tmp, pip);
	tmp = tmp->next_pipe;
	while (tmp != NULL)
	{
		if (pipe(pip) == -1)
			return (-1);
		exec_cmd(master, tmp, pip);
		tmp = tmp->next_pipe;
	}
	wait_all(master);
	return (0);
}
