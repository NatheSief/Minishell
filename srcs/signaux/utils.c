/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:39:35 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/18 19:49:10 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Déclaration de la fonction pour gérer le signal SIGINT
static void sigint_handler(int sig, t_shell *shell) {
    if (shell->state == e_shell_idle) {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    } else if (shell->state == e_shell_heredoc) {
        printf("\nHere-doc interrupted\n");
        shell->state = e_shell_idle;
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
    } else if (shell->state == e_shell_exec) {
        printf("\nProgram interrupted by Ctrl-C\n");
        // kill(pid, SIGINT); // En supposant que vous avez gardé le pid du processus
    }
}

// Déclaration de la fonction pour gérer le signal SIGQUIT (Ctrl-\)
static void sigquit_handler(int sig, t_shell *shell) {
    if (shell->state == e_shell_exec) {
        printf("Quit (core dumped)\n");
        shell->state = e_shell_idle; // Retour à l'état shell normal
    }
}

// Configuration des gestionnaires de signaux
void setup_signals(t_shell *shell) {
    signal(SIGINT, (void (*)(int))sigint_handler);  // Gérer Ctrl-C
    signal(SIGQUIT, (void (*)(int))sigquit_handler); // Gérer Ctrl- '\'
}
