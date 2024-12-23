/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:19:33 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 18:50:19 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_to_end_cmd(t_shell *master, t_cmd *cmd)
{
    t_cmd *tmp;

    tmp = master->command;
    while (tmp->next_pipe)
        tmp = tmp->next_pipe;
    tmp->next_pipe = cmd;
}

t_cmd   *create_new_cmd(void)
{
    t_cmd   *new;

    new = malloc(sizeof(t_cmd));
    if (!new)
        return (NULL);
    new->skipable = 0;
    new->input = -1;
    new->output = -1;
    new->cmd[0] = NULL;
    new->cmd[1] = NULL;
    new->next_pipe = NULL;
    return (new);
}
