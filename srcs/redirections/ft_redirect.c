/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:04:18 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 15:38:41 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Redirect the input file on the STDIN and the output on the STDOUT
void	redirect_in_out(t_cmd *cmd, int *fd)
{
	close(fd[0]);
	if (cmd->input >= 0)
	{
		dup2(cmd->input, STDIN_FILENO);
		close(cmd->input);
	}
	if (cmd->output >= 0)
	{
		dup2(cmd->output, STDOUT_FILENO);
		close(cmd->output);
	}
	close(fd[1]);
}

int	get_input(t_shell *master, t_token *token, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_in(master, cmd, tmp))
		return (1);
	if (tmp->type == PIPE)
		return (0);
	tmp = tmp->next_token;
	while (tmp->type != PIPE && tmp != *master->token)
	{
		if (!get_in(master, cmd, tmp))
			return (1);
		tmp = tmp->next_token;
	}
	return (0);
}

int	get_output(t_shell *master, t_token *token, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_out(master, cmd, tmp))
		return (1);
	tmp = tmp->next_token;
	while (tmp != *master->token && tmp->type != PIPE)
	{
		if (!get_out(master, cmd, tmp))
			return (1);
		tmp = tmp->next_token;
	}
	return (0);
}
