/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:53:07 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/15 15:23:46 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Change the value of a name_variable in the environment
int	change_env(t_shell *shell, char *name, char *value)
{
	t_list *tmp;

	tmp = shell->env;
	while (tmp->next)
	{
		if (!ft_strncmp((char *)tmp->value), name, ft_strlen(name))
			break;
		tmp = tmp->next;
	}
	if (!tmp->next)
		return (1);
	else
		free(tmp->value);
	tmp->value = (void *)ft_strdup(value);
	if (!tmp->value)
		return (1);
	return (0);
}
