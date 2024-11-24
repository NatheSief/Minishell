/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_cmd_first_node.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:39:04 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 19:40:30 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Return the first node of the last command line
t_cmd	*get_last_cmd_first_node(t_shell *shell)
{
	t_cmd	*tmp;

	tmp = shell->head;
	while (tmp->next_cmd)
		tmp = tmp->next_cmd;
	return (tmp);
}
