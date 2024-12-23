/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:15:02 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 18:44:33 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_cmd_struct(t_token *tkn, t_cmd *cmd)
{
	if (cmd->output == -1 || cmd->input == -1)
		return (1);
	while (tkn && tkn->type != PIPE)
	{
		if (tkn->type == HEREDOC || tkn->type == INPUT )
		{
			if (cmd->input == 0)
				return (1);
			tkn = tkn->next_token;
		}
		else if (tkn->type == APPEN || tkn->type == OUTPUT )
		{
			if (cmd->input == 1)
				return (1);
			tkn = tkn->next_token;
		}
	}
	return (0);
}
