/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:05:53 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:05:54 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_dir(char **path, char *cmd, t_shell *master)
{
	struct stat	path_stat;

	stat(*path, &path_stat);
	if (!S_ISREG(path_stat.st_mode))
	{
		print_error(cmd);
		print_error(" : Is a directory\n");
		master->ret_value = 126;
		return (1);
	}
	return (0);
}

static int	cmd_exist(char **path, t_shell *master, char *cmd)
{
	if (!ft_strchr(cmd, '/'))
		*path = find_cmd(master, cmd, master->env);
	else
		absolute_path(path, cmd, master);
	if (!(*path) && master->ret_value == -1)
		free_all(master, NULL, master->ret_value);
	if (!(*path))
	{
		master->ret_value = 127;
		return (1);
	}
	if (access((*path), X_OK))
	{
		perror(*path);
		free((*path));
		(*path) = NULL;
		master->ret_value = 126;
		return (1);
	}
	if (!check_dir(path, cmd, master))
		return (1);
	return (0);
}

static void	redirect_in_out(t_shell *master, t_cmd *cmd, int *pip)
{
	close(pip[0]);
	if (cmd->input >= 0)
	{
		dup2(cmd->input, 0);
		close(cmd->input);
	}
	if (cmd->output >= 0)
	{
		dup2(cmd->output, 1);
		close(cmd->output);
	}
	else if (cmd->next_pipe != master->command)
		dup2(pip[1], 1);
	close(pip[1]);
}

static void	built(t_shell *master, t_cmd *cmd, int *pip)
{
	close(pip[0]);
	if (cmd->output < 0 && cmd->next_pipe != master->command)
		cmd->output = pip[1];
	else
		close(pip[1]);
	launch_builtin(master, cmd);
}

void	child_process(t_shell *master, t_cmd *cmd, int *pip)
{
	char	*path;
	char	**env;

	path = NULL;
	if (cmd->skipable)
		master->ret_value = 1;
	else if (is_builtin(cmd->cmd[0]))
		built(pip, cmd, master);
	else if (cmd_exist(&path, master, cmd->cmd[0]))
	{
		redirect_in_out(master, cmd, pip);
		env = lst_to_arr(master->env);
		if (!env)
			free_all(master, "MALLOC ERROR", 1);
		rl_clear_history();
		signals2();
		execve(path, cmd->cmd, env);
		free(env);
	}
	if (path)
		free(path);
	free_all(master, NULL, master->ret_value);
}
