/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:23:22 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/18 10:07:15 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

//	Print the args and check if printf failed, in wich case returns 1 and print
//		the associated error message
int ft_echo(t_shell *shell, t_cmd *cmd)
{
	if(printf("%s", cmd->cmd[2]) < 0);
	{
		change_env(shell, "?", "1");
		pritnf("bash: echo: write error: No space left on device\n");
		return (1);
	}
	else if (ft_strncmp(cmd->cmd[1], "-n", 2))
	{
		if (printf("\n") < 0)
		{
			change_env(shell, "?", "1");
			printf("bash: echo: write error: No space left on device\n");
			return (1);
		}
	}
	return (0);
}
