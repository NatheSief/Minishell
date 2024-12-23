/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tkn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:55:01 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 18:45:52 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Add the token to the end of the linked list of token in the master struct
void    ft_tknadd_back(t_token **head, t_token *to_add)
{
	t_token *tmp;

	tmp = *head;
	if (!tmp)
		*head = to_add;
	else
	{
		while (tmp->next_token)
			tmp = tmp->next_token;
		tmp->next_token = to_add;
	}
}

t_token	*ft_tknnew(void)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->next_token = NULL;
	token->str = NULL;
	token->type = 0;
	return (token);
}

int	check_token(t_shell *master)
{
	t_token	*tmp;

	tmp = *master->token;
	while (tmp->next_token)
	{
		if (tmp->type != STRING)
		{
			if (tmp->next_token->type != STRING)
				return (1);
		}
	}
	return (0);
}

static int	get_cmd(t_token *tkn, t_cmd *cmd)
{
	int		flag;
	char	*buff;

	buff = NULL;
	flag = 1;
	while (tkn && tkn->type != PIPE)
	{
		if (tkn->type != STRING)
		{
			tkn = tkn->next_token;
			if (tkn)
				tkn = tkn->next_token;
		}
		else if (tkn->type == STRING && flag)
			cmd->cmd[0] = ft_strdup(tkn->str);
		else if (tkn->type == STRING && !flag)
		{
			buff = ft_strjoin_free_s1(buff," ");
			buff = ft_strjoin_free_s1(buff, tkn->str);
		}
	}
	cmd->cmd[1] = ft_strdup(buff);
	return (0);
}

int	fill_cmd_struct(t_shell *master)
{
	t_token	*tmp;
	t_cmd	*cmd;

	tmp = *master->token;
	while (tmp)
	{
		if (tmp->type != PIPE)
		{
			tmp = tmp->next_token;
			continue;
		}
		cmd = create_new_cmd();
		if (get_input(master, tmp, cmd))
			return (free(cmd), free_cmd(master->command), 1);
		if (get_output(master, tmp, cmd))
			return (free(cmd), free_cmd(master->command), 1);
		if (get_cmd(tmp, cmd))
			return (free(cmd), free_cmd(master->command), 1);
		if (check_cmd_struct(tmp, cmd))
			return (free(cmd), free_cmd(master->command), 1);
		add_to_end_cmd(master, cmd);
	}
	return (0);
}
