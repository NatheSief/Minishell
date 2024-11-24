/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:05:10 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/18 10:02:04 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Unset a value of the environment :
//		- If there is an error, I juste return (-1)
//		- Else it remove the value from the t_list and return (0)
int	ft_unset(t_shell *shell, t_cmd *cmd)
{
	if (rmv_lst(&shell->env, t_cmd->cmd[2]))
		return (-1);
	return (0);
}

