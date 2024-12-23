/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:05:10 by Nathe             #+#    #+#             */
/*   Updated: 2024/12/24 15:25:25 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Unset a value of the environment :
//		- If there is an error, I juste return (-1)
//		- Else it remove the value from the t_list and return (0)
int	ft_unset(t_shell *master, t_cmd *cmd)
{
	if (rmv_lst(master->env, cmd->cmd[1]))
		return (printf("bash: unset: Cannot remove %s\n", cmd->cmd[1]), 1);
	return (0);
}

