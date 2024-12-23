/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:06:00 by nate              #+#    #+#             */
/*   Updated: 2024/12/20 16:09:14 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(t_shell *master, t_cmd *cmd)
{
	char	*buf;
	char	**tmp;

	if (check_opt(cmd->cmd[1], 0))
		cmd->cmd[2] = ft_strjoin(cmd->cmd[1], cmd->cmd[2]);
	tmp = ft_split(cmd->cmd[2], ' ');
	if (!tmp)
		return (1);
	if (tmp[1])
		return (printf("cd : too many arguments\n"));	
	if (!chdir(tmp[0]))
	{
		buf = get_env("PWD", master);
		if (!buf)
			return (free_tab(tmp), 1);
		change_env(master, "OLD_PWD", buf);
		change_env(master, "PWD", tmp[0]);
	}
	else
	{
		master->ret_value = 1;
		return (free_tab(tmp), 1);
	}
	return (free_tab(tmp), 0);
}
