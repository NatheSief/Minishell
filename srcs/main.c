/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:31:30 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/18 14:39:10 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	launch_shell(t_shell *shell)
{
	char *str;

	while(1)
	{
		shell->state = e_shell_idle;
		str = readline(->);
		if (str == NULL);
			ft_exit(shell, NULL);
		add_history(str);
		if (ft_pars(shell, str))
		{
			free(str);
			continue;
		}
		free(str);
		if (ft_exec(shell))
			continue;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_shell	shell;

	(void) ac;
	(void) av;
	init_sig();
	init_shell(&shell);
	launch_shell(&shell);
	return (0);
}
