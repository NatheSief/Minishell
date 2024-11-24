/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_sample.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:51:22 by nate              #+#    #+#             */
/*   Updated: 2024/11/19 17:14:53 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pars(char *input, t_cmd *cmd, t_shell *shell)
{
    char *token;
    char *rest = input;
    int arg_count = 0;

    ft_memset((void *)cmd, 0, sizeof(t_cmd)); // Initialiser la structure de la commande
    while ((token = strtok_r(rest, " ", &rest))) {
        if (strcmp(token, "<") == 0) {
            parse_redir_input(&rest, cmd);  // Gestion des here-doc
        } else if (strcmp(token, ">") == 0) {
            parse_redir_output(&rest, cmd, 0); // Redirection de sortie
        } else if (strcmp(token, ">>") == 0) {
            parse_redir_output(&rest, cmd, 1); // Redirection de sortie append
        } else if (strcmp(token, "|") == 0) {
            parse_pipe(&rest, cmd, shell); // Gestion des pipes
            break;
        } else {
            parse_arguments(token, cmd, &arg_count); // Ajouter les arguments
        }
    }
    return 0;
}

