/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:08:39 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 10:35:07 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_file(t_shell *master, char *filename, int type)
{
	int	fd;

	fd = -2;
	if (type == INPUT)
		fd = open(filename, O_RDONLY, 0644);
	else if (type == HEREDOC)
		fd = here_doc(master, filename);
	else if (type == OUTPUT)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == APPEN)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (type != HEREDOC && fd < 0)
		perror(filename);
	return (fd);
}

int	get_in(t_shell *master, t_cmd *cmd, t_token *tmp)
{
	if (tmp->type == INPUT)
	{
		if (cmd->input >= 0)
			close(cmd->input);
		if (tmp == tmp->next_token || tmp->next_token->type <= 5)
			return (print_error_token(master, tmp));
		cmd->input = open_file(master, tmp->next_token->str, INPUT);
		if (cmd->input == -1)
			return (1);
	}
	else if (tmp->type == HEREDOC)
	{
		if (cmd->input >= 0)
			close(cmd->input);
		if (tmp == tmp->next_token || tmp->next_token->type <= 5)
			return (print_error_token(master, tmp));
		cmd->input = open_file(master, tmp->next_token->str, HEREDOC);
		if (cmd->input == -1)
			return (1);
	}
	return (0);
}

int	get_out(t_shell *master, t_cmd *cmd, t_token *tmp)
{
	if (tmp->type == OUTPUT)
	{
		if (cmd->output >= 0)
			close(cmd->output);
		if (tmp == tmp->next_token || tmp->next_token->type <= 5)
			return (print_error_token(master, tmp));
		cmd->output = open_file(NULL, tmp->next_token->str, OUTPUT);
		if (cmd->output == -1)
			return (1);
	}
	else if (tmp->type == APPEN)
	{
		if (cmd->output >= 0)
			close(cmd->output);
		if (tmp == tmp->next_token || tmp->next_token->type <= 5)
			return (print_error_token(master, tmp));
		cmd->output = open_file(NULL, tmp->next_token->str, APPEN);
		if (cmd->output == -1)
			return (1);
	}
	return (0);
}
