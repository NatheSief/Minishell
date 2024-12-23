/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filll_cmd_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:14:01 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 19:55:24 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  _get_input(t_token *tkn, t_cmd *cmd)
{
    t_token *tmp;
    t_token *stock;

    tmp = tkn;
    stock = NULL;
    while (tmp->type != PIPE)
    {
        if (tmp->type == INPUT || tmp->type == HEREDOC)
            stock = tmp;
        tmp = tmp->next_token;
    }
    if (stock)
    {
        cmd->input = open(stock->next_token->str, O_RDWR);
        if (cmd->input != -1)
            return (0);
        else
            return (1);
    }
    else
    {
        cmd->input = 0;
        return (0);
    }
    return (1);
}

static int   _get_output(t_token *tkn, t_cmd *cmd)
{
    t_token *tmp;
    t_token *stock;

    tmp = tkn;
    stock = NULL;
    while (tmp->type != PIPE)
    {
        if (tmp->type == OUTPUT || tmp->type == APPEN)
            stock = tmp;
        tmp = tmp->next_token;
    }
    if (stock)
    {
        cmd->output = open(stock->next_token->str, O_RDWR);
        if (cmd->output != -1)
            return (0);
        else
            return (1);
    }
    else
    {
        cmd->output = 1;
        return (0);
    }
    return (1);
}

//  Get the first STRING token value that is not after a redirection 
static int get_cmd(t_token *tkn, t_cmd *cmd)
{
    t_token *tmp;

    tmp = tkn;
    while (tmp->type != PIPE)
    {
            if (tmp->type != STRING)
            {
                tmp = tmp->next_token;
                if (tmp)
                    tmp = tmp->next_token;
                else 
                    return (1);
            }
            else
            {
                cmd->cmd[0] = ft_strdup(tmp->str); 
                return (0);
            }
    }
    return (1);
}

//  Add a new cmd struct at the end of the linked list in the master struct
void    ft_cmdadd_back(t_cmd **head, t_cmd *new)
{
    t_cmd   *tmp;

    tmp = *head;
    if (!tmp)
        *head = new;
    else
    {
        while (tmp->next_pipe)
            tmp = tmp->next_pipe;
        tmp->next_pipe = new;
    }
}

static int  get_args(t_token *tkn, t_cmd *cmd)
{
    t_token *tmp;
    char    *args;
    char    **tab;

    args = NULL;
    tmp = tkn;
    while (tmp && tmp->type != PIPE)
    {
        if (tmp->type != STRING)
            tmp = tmp->next_token;
        else
        {
            args = ft_strjoin_free_s1(args," ");
            args = ft_strjoin_free_s1(args, tmp->str);
        }
        if (tmp->type == PIPE)
            return(free(args), 1);
        tmp = tmp->next_token;
    }
    tab = ft_ms_split(args);
    if (!tab)
        return (free(args), 1);
    cmd->cmd[0] = ft_strdup(tab[0]);
    cmd->cmd[1] = ft_strdup(args + ft_strlen(cmd->cmd[0]));
    return (free_tab((void **)tab), free(args), 0);
}

//  Fill the cmd struct by checking the tokens (for cmd, args, input/output)...
int fill_cmd_struct(t_shell *master)
{
    t_token *tmp;
    t_cmd   *cmd;

    tmp = *master->token;
    while (tmp)
    {
        cmd = create_new_cmd();
        if (!cmd)
            return (free_cmd(master->command), 1);
        _get_input(tmp, cmd);
        _get_output(tmp, cmd);
        get_cmd(tmp, cmd);
        get_args(tmp, cmd);
        ft_cmdadd_back(master->command, cmd);
        while(tmp->next_token)
        {
            if (tmp->type != PIPE)
                tmp = tmp->next_token;
            else
                break ;
        }
    }
    return (0);
}
