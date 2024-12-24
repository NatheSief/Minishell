/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:43:50 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 13:00:57 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	launch_shell(t_shell *master)
{
	char	*str;

	while (1)
	{
		master->state = e_shell_idle;
		str = readline("->");
		if (str == NULL)
			break ;
		add_history(str);
		if (ft_pars(master, str))
		{
			free(str);
			continue ;
		}
		free(str);
		if (tokenizator(master, str))
		{
			free(str);
			continue;
		}
		ft_exec(master);
		free_cmd(master->command);
		free_token(master->token);
	}
}

int main(int ac, char **av, char **envp)
{
	t_shell master;

	(void)ac;
	(void)av;
	if (init_shell(&master, envp))
		return (1);
	launch_shell(&master);
	free_all(&master, NULL, 0);
}
