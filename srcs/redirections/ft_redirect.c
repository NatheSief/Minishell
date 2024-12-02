/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:04:18 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:05:22 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Redirect the input file on the STDIN and the output on the STDOUT
void    redirect_in_out(t_shell *master, t_cmd *cmd, int *fd)
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

int	get_infile(t_shell *data, t_token *token, t_cmd *cmd)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_in(data, tmp, cmd))
		return (1);
	if (tmp->type == PIPE)
		return (0);
	tmp = tmp->next_token;
	while (tmp->type != PIPE && tmp != data->token)
	{
		if (!get_in(data, tmp, cmd))
			return (1);
		tmp = tmp->next_token;
	}
	return (0);
}

int	output(t_token *token, t_cmd *cmd, t_shell *data)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type != PIPE && !get_out(tmp, cmd, data))
		return (1);
	tmp = tmp->next_token;
	while (tmp != data->token && tmp->type != PIPE)
	{
		if (!get_out(tmp, cmd, data))
			return (1);
		tmp = tmp->next_token;
	}
	return (0);
}
