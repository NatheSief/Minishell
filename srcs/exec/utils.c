/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:41:30 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 19:46:26 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Create a pipe into a fd tab
void	create_pipe(int fd[2]) 
{
	if (pipe(fd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

//	Create a fork and check if there is no error during the creation
pid_t	fork_process() 
{
	pid_t pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

//	Find the path to the command to execute via the path in the env
char	*get_cmd(t_shell *shell, t_cmd *cmd)
{
	char	**paths;
	char	to_ret;
	int		i;

	paths = ft_split(get_env(shell, "PATH"), ':');
	if (!paths)
		return (NULL);
	i = -1;
	while(paths[++i])
	{
		to_ret = ft_strjoin(paths[i], cmd->cmd[0]);
		if (!access(to_ret, F_OK))
			continue;
		else
			return (to_ret);
	}
	return (NULL);
}
