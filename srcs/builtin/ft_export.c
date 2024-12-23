/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:13:42 by Nathe             #+#    #+#             */
/*   Updated: 2024/12/20 16:21:36 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_shell *master, t_cmd *cmd)
{
	t_list	*new;

	if (cmd->cmd[1] && check_opt(cmd->cmd[1], 0))
		cmd->cmd[2] = ft_strjoin(cmd->cmd[1], cmd->cmd[2]);
	new = ft_lstnew(cmd->cmd[2]);
	if (!new)
		return (1);
	ft_lstadd_back(master->env, ft_lstnew(cmd->cmd[2]));
	return (0);	
}
