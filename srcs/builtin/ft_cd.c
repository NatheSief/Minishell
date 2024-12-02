/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:06:00 by nate              #+#    #+#             */
/*   Updated: 2024/11/30 16:37:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(t_shell *master, t_cmd *cmd)
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
