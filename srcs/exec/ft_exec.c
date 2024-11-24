/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:01:02 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 19:44:54 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//	Find if the command is a builtin;
int execute_builtin(t_cmd *cmd, t_shell *shell) 
{
	char **args ;

	args = ft_split(cmd, ' ');
	if (!ft_strncmp(args[0], "echo", 4) && !ft_strncmp(args[1], "-n", 2))
		return (ft_echo(shell, args));
	else if (!ft_strncmp(args[0], "pwd", 3) && !args[1])
		return (ft_pwd(shell));
	else if (!ft_strncmp(args[0], "cd", 2) && !args[1])
		return (ft_cd(args, shell));
	else if (!ft_strncmp(args[0], "env", 3) && !args[1][0])
		return (ft_env(shell->env));
	else if (!ft_strncmp(args[0], "export", 6) && !args[1])
		return (ft_export(args, shell));
	else if (!ft_strncmp(args[0], "unset", 5) && !args[1])
		return (ft_unset(args, shell));
	else if (!ft_strncmp(args[0], "exit", 5) && !args[1])
		return (ft_exit(args, shell));
	return (-1);
}

//	Execute the command with execve if it's not a builtin or if I don't handle the 
//		options of this builtin
void execute_command(t_cmd *cmd, t_shell *shell) 
{
	char	*path ;
	char	**env;

	env = convert_list_tab(shell->env);
	if (!env)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	path = get_cmd(shell, cmd->cmd[0]);
	if (!path)
	{
		perror("path");
		free_tab(env);
		exit(EXIT_FAILURE);
	}
	if (execve(path, cmd->cmd[2], env) == -1) 
	{
		perror("execve");
		free_tab(env);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void exec_child_process(t_cmd *current, int input_fd, int fd[2], t_shell *shell) 
{
	if (current->input != 0)
		dup2(current->input, STDIN_FILENO);
	else if (input_fd != 0)
		dup2(input_fd, STDIN_FILENO);
	if (current->output != 1)
		dup2(current->output, STDOUT_FILENO);
	else if (current->next_pipe != NULL)
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	if (execute_builtin(current, shell) == -1) 
		execute_command(current, shell);
	exit(EXIT_SUCCESS);
}

void exec_parent_process(pid_t pid, int fd[2], int *input_fd, t_cmd *current, \
	t_shell *shell) 
{
	int status;

	waitpid(pid, &status, 0);
	shell->ret_value = WEXITSTATUS(status);
	if (*input_fd != 0)
		close(*input_fd);
	close(fd[1]);
	*input_fd = fd[0];
	if (current->next_pipe)
	    current = current->next_pipe;
	else
	    current = current->next_cmd;
}

void ft_exec(t_shell *shell)
{
	t_cmd *current;
	int input_fd;
	pid_t pid;
	int fd[2];

	input_fd = 0;
	current = get_last_cmd_first_node(shell);
	while (current != NULL) {
		if (current->next_pipe != NULL)
			create_pipe(fd);
		pid = fork_process();
		if (pid == 0)
			exec_child_process(current, input_fd, fd, shell);
		else
			exec_parent_process(pid, fd, &input_fd, current, shell);
		if (current->next_pipe == NULL || shell->ret_value)
			break;
		current = current->next_pipe;
    }
}
