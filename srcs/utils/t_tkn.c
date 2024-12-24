/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tkn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 17:06:30 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 17:18:54 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_tknnew(void)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	return (new);
}

void	ft_tknadd_back(t_token **head, t_token *new)
{
	t_token	*tmp;

	tmp = *head;
	if (!tmp)
	{
		*head = new;
		return ;
	}
	while (tmp->next_token)
		tmp = tmp->next_token;
	tmp->next_token = new;
}

int	check_token(t_shell *master)
{
	t_token	*tmp;

	tmp = *master->token;
	while (tmp)
	{
		if (tmp->type != STRING)
		{
			if (tmp->next_token->type != STRING)
				return (1);
		}
	}
	return (0);
}
