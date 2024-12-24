/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:05:53 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 15:10:27 by nsiefert         ###   ########.fr       */
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
		*path = find_cmd(master, cmd);
	else if (absolute_path(master, cmd, path))
		return (0);
	if (!(*path) && master->ret_value == -1)
		free_all(master, NULL, master->ret_value);
	if (!(*path))
	{
		master->ret_value = 127;
		return (0);
	}
	if (access((*path), X_OK))
	{
		perror(*path);
		free((*path));
		(*path) = NULL;
		master->ret_value = 126;
		return (0);
	}
	if (!check_dir(path, cmd, master))
		return (0);
	return (1);
}

static void	_redirect_in_out(t_cmd *cmd, int *pip)
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
	else if (cmd->next_pipe)
		dup2(pip[1], 1);
	close(pip[1]);
}

static void	built(t_shell *master, t_cmd *cmd, int *pip)
{
	close(pip[0]);
	if (cmd->output < 0 && cmd->next_pipe)
		cmd->output = pip[1];
	else
		close(pip[1]);
	launch_builtin(master, cmd);
}

char	**lst_to_tab(t_list **head)
{
	char	**tab;
	int		size_list;
	t_list	*tmp;
	int		i;

	i = -1;
	size_list = ft_lst_size(*head);
	tab = malloc(sizeof(char *) * size_list);
	if (!tab)
		return (NULL);
	tmp = *head;
	while (tmp)
	{
		tab[++i] = ft_strdup((char *)tmp->content);
		if (!tab[i])
			return (free_tab((void **)tab), NULL);
		tmp = tmp->next;
	}
	return (tab);
}

void	child_process(t_shell *master, t_cmd *cmd, int *pip)
{
	char	*path;
	char	**env;

	path = NULL;
	if (cmd->skipable)
		master->ret_value = 1;
	else if (is_builtin(cmd->cmd[0]))
		built(master, cmd, pip);
	else if (cmd_exist(&path, master, cmd->cmd[0]))
	{
		_redirect_in_out(cmd, pip);
		env = lst_to_tab(master->env);
		if (!env)
			free_all(master, "MALLOC ERROR", 1);
		rl_clear_history();
		execve(path, cmd->cmd, env);
		free(env);
	}
	if (path)
		free(path);
	free_all(master, NULL, master->ret_value);
}
