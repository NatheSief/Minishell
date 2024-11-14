/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:05:10 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/13 18:13:12 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Unset a value of the environment
int	ft_unset(t_shell *shell, t_cmd *cmd)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = shell->env;
	while (ft_strncmp((char *)tmp->content), cmd->cmd[2], ft_strlen(cmd->cmd[2]))
	{
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp2->next = tmp->next;
	free(tmp);
}
