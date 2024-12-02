/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:58:47 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 09:45:16 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    print_error(char *str)
{
    write(2, str, ft_strlen(str));
}

//	Free the token list, and also the strings associated to the tokens
void	free_token(t_token	**token)
{
	t_token	*tmp;
	t_token	*save;

	tmp = *token;
	while (tmp)
	{
		free(tmp->str);
		save = tmp;
		tmp=tmp->next_token;
		free(save);
	}
	free(token);
}

//	Free the cmd list, and also the char tab that contains the commands
void	free_cmd(t_cmd	**command)
{
	t_cmd	*save;
	t_cmd	*tmp;

	tmp = *command;
	while(tmp)
	{
		free_tab(tmp->cmd);
		save = tmp;
		tmp = tmp->next_pipe;
		free(save);
	}
	free(command);
}

void	free_all(t_shell *master, char *err, int ext)
{
	if (master->command)
		free_cmd(&master->command);
	if (master->token)
		free_token(&master->token);
	if (master->env)
		ft_lstclear(&master->env, free);
	if (master->fd[0] && master->fd[0] != -1)
		close(master->fd[0]);
	if (master->fd[1] && master->fd[1] != -1)
		close(master->fd[1]);
	if (err)
		print_error(err);
	rl_clear_history();
	if (!access(".heredoc.tmp", F_OK))
		unlink(".heredoc.tmp");
	if (ext != -1)
		exit(ext);
}
