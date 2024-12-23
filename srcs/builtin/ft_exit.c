/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:08:30 by Nathe             #+#    #+#             */
/*   Updated: 2024/12/20 16:20:06 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Exit the shell or the sub-shell with the error value that was in arg if it 
//		was;
int	ft_exit(t_shell *master, t_cmd *cmd)
{
	int	value;

	value = master->ret_value;
	printf("exit");
	if (cmd->cmd[1] && check_opt(cmd->cmd[1], 0))
		cmd->cmd[2] = ft_strjoin(cmd->cmd[1], cmd->cmd[2]);
	else if (cmd->cmd[2] && check_digit(cmd->cmd[2]))
		printf("bash: exit: %s: numeric argument required\n", cmd->cmd[2]);
	if (cmd)
	{
		if (cmd->cmd[2])
			value = ft_atoi(cmd->cmd[2]);
	}
	clear_shell(master);
	exit(value);
	return (1);
}
