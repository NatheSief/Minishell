/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:23:22 by Nathe             #+#    #+#             */
/*   Updated: 2024/12/24 15:17:15 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Print the args and check if printf failed, in wich case returns 1 and print
//		the associated error message
int ft_echo(t_shell *master, t_cmd *cmd)
{
	int		flag;

	flag = 0;
	// if (cmd->cmd[1] && check_opt(cmd->cmd[1], 'n'))
	// 	cmd->cmd[2] = ft_strjoin(cmd->cmd[1], cmd->cmd[2]);
	// else
	// 	flag = 1;
	if (printf("%s", cmd->cmd[1]) < 0)
	{
		master->ret_value = 1;
		return (perror("bash : echo : write error"), 1);
	}
	else if (!flag)
	{
		if (printf("\n") < 0)
		{
			master->ret_value = 1;
			return (perror("bash : echo : write error"), 1);
		}
	}
	return (0);
}
