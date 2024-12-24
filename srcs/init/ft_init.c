/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:09:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 13:01:51 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t   g_signal_pid;

//  Copy the environment I have as parameter into a linked list
//      If at any moment I have a malloc that crash, I free everything before
//      then I return __NULL__, else I return a pointer on the head of the list
static t_list  **copy_env(char **envp)
{
    int     i;
    t_list  **head;
    t_list  *tmp;
    char    *duplicated;

    i = 0;
    head = NULL;
    duplicated = ft_strdup(envp[0]);
    if (!duplicated)
        return (NULL);
    tmp = ft_lstnew((void *)duplicated);
    if (!tmp)
        return (free(duplicated), NULL);
    *head = tmp;
    while (envp[++i])
    {
        duplicated = ft_strdup(envp[i]);
        if (!duplicated)
            return (ft_lstclear(head, free), NULL);
        tmp->next = ft_lstnew((void *)duplicated);
        if (!tmp->next)
            return (free(duplicated), ft_lstclear(head, free), NULL);
        tmp = tmp->next;
    }
    return (head);
}

//  Check if I have an environment :
//      If I have one, I will just copy it -- cf copy_env()
//      If I don't, I will just create a new one -- cf create_minimal_env();
static int  _get_env(t_shell *master, char **envp)
{
    if (envp == NULL)
        return (1);
    else
        master->env = copy_env(envp);
    if (master->env == NULL)
        return (1);
    return (0);
}

int init_shell(t_shell *master, char **envp)
{
    master->ret_value = 0;                  //  The return value is 0 before the execution
    master->state = e_shell_idle;           //  We are waiting for a command
    master->command = NULL;                 //  There is no command at start
    master->token = NULL;                   //  There is no token at start
    master->input_fd = -1;                  //  Put that to -1 it's easier
    master->fd[0] = -1;                     //  Put that to -1 it's easier
    master->fd[1] = -1;                     //  Put that to -1 it's easier
    g_signal_pid = 0;                       //  Put the global to 0
    init_sig(master);                       //  Init the signals for the entierty of the execution
    if (_get_env(master, envp))              //  We will copy the environment variables into the shell struct
        return (1);
    return (0);
}
