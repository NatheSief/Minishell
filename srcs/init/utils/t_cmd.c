/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 20:19:33 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:04:38 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void    add_to_end_cmd(t_shell *master, t_cmd *cmd)
{
    t_cmd *tmp;

    tmp = master->command;
    while (tmp->next_pipe)
        tmp = tmp->next_pipe;
    tmp->next_pipe = cmd;
}

static int create_new_cmd(t_cmd *new, char **cmd, int infile, int outfile)
{
    new = malloc(sizeof(t_cmd));
    if (!new)
        return (1);
    new->skipable = 0;
    new->input = infile;
    new->output = outfile;
    new->cmd = cmd;
    new->next_pipe = NULL;
    return (0);
}

int init_new_cmd(t_shell *master, char **cmd, int infile, int outfile)
{
    t_cmd   *new;

    new = NULL;
    if (create_new_cmd(new, cmd, infile, outfile))
        return (1);
    if (!master->command)
    {
        master->command = new;
        new->next_pipe = NULL;
    }
    else
        add_to_end_cmd(master, cmd);
    return (0);
}
