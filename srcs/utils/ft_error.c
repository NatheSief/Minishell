/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:18:56 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/14 17:23:49 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Error for the builtin echo
void	echo_error_handle(int code)
{
	if (code == 1)
		printf("echo : No space left on device\n");
}

// Error Handle for the builtins or the commands
int	ft_error(t_cmd *cmd, int code)
{
	printf("bash : ");
	if (!ft_strncmp(cmd->cmd[0], "echo", 4))
		echo_error_handle(code);
}

