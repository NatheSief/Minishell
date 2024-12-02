/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:13:42 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/30 16:37:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export(t_shell *master, t_cmd *cmd)
{
	t_list	*new;

	new = ft_lstnew(cmd->cmd[3]);
	if (!new)
		return (1);
	ft_lstadd_back(&shell->head, ft_lstnew(cmd->cmd[3]));
	return (0);	
}
