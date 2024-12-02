/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:57:37 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/01 20:23:05 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Fonction pour gérer le signal SIGINT
static void sigint_handler(int sig, t_shell *master)
{
    if (master->state == e_shell_idle)
    {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
    else if (master->state == e_shell_heredoc)
    {
        printf("\nHere-doc interrupted\n");
        master->state = e_shell_idle;
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    }
    else if (master->state == e_shell_exec)
    {
        printf("\nProgram interrupted by Ctrl-C\n");
        // kill(pid, SIGINT); // Si j'ai garde le PID
    }
}

//  Fonction pour gérer le signal SIGQUIT
static void sigquit_handler(int sig, t_shell *master)
{
    if (master->state == e_shell_exec)
    {
        printf("Quit (core dumped)\n");
        master->state = e_shell_idle; // Retour à l'état shell normal
    }
}

// Configuration gestion de signaux
//      SIGINT  ==  Ctrl-C
//      SIGQUIT ==  Ctrl-'\'
void    init_sig(t_shell *master)
{
    signal(SIGINT, (void (*)(int))sigint_handler);
    signal(SIGQUIT, (void (*)(int))sigquit_handler);
}
