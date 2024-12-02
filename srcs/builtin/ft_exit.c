/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:08:30 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/30 16:37:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Exit the shell or the sub-shell with the error value that was in arg if it 
//		was;
int	ft_exit(t_shell *master, t_cmd *cmd)
{
	int	value;

	value = shell->ret_value;
	printf("exit");
	if (cmd)
	{
		if (cmd->cmd[2])
			value = ft_atoi(cmd->cmd[2]);
	}
	clear_shell(shell);
	exit(value);
	return (1);
}
