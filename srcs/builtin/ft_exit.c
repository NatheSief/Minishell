/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:08:30 by Nathe             #+#    #+#             */
/*   Updated: 2024/12/24 15:20:03 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
	}
	return (0);
}

//	Exit the shell or the sub-shell with the error value that was in arg if it 
//		was;
int	ft_exit(t_shell *master, t_cmd *cmd)
{
	int	value;

	value = master->ret_value;
	printf("exit");
	if (cmd->cmd[1] && check_digit(cmd->cmd[1]))
		printf("bash: exit: %s: numeric argument required\n", cmd->cmd[1]);
	if (cmd)
	{
		if (cmd->cmd[1])
			value = ft_atoi(cmd->cmd[1]);
	}
	free_all(master, NULL, value);
	exit(value);
	return (1);
}
