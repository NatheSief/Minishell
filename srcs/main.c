/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:43:50 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 09:47:45 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    launch_shell(t_shell *master)
{
    char    *str;

    while (1)
    {
        master->state = e_shell_idle;   //  ->  Put the shell state as idle for the signals
        str = readline("->");           //  ->  Read my user entry to get the command to exec
        if (str == NULL)
            break ;                     //  ->  If my string is EOF it means I have Ctrl+D so I close my programm and EOF == NULL
        add_history(str);
        if (ft_pars(master, str))
        {
            free(str);
            continue ;
        }
        free(str);
        ft_exec(master);
        free_cmd(master->command);
        free_cmd(master->token);
    }
}

int main(int ac, char **av, char **envp)
{
    t_shell master;

    (void)ac;
    (void)av;
    if (init_shell(&master, envp))  //      ->  Init the values of the master, get the env, ...
        return (1);
    launch_shell(&master);          //      ->  Launch a while(1) loop
    free_all(&master, NULL, 0);     //      ->  Clean all the mallocs and exit the programm with 0
}
