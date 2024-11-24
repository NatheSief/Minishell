/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:08:30 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/18 14:21:37 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Exit the shell or the sub-shell with the error value that was in arg if it 
//		was;
int	ft_exit(t_shell *shell, t_cmd *cmd)
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
