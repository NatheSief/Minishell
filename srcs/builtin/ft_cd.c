/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:06:00 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 11:45:14 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int ft_cd(t_shell *shell, t_cmd *cmd)
{
	char	*buf;

	if (!chdir(cmd.cmd[2]))
	{
		buf = get_env(PATH);
		if (!buf)
			return (1);
		change_env(shell, "OLD_PATH", buf);
		change_env(shell, "PATH", cmd.cmd[2]);
		free(buf);
	}
	else
	{
		change_env(shell, "?", "1");
		return (1);
	}
	return (0);
}
