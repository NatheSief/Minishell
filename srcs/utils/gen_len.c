/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:53:16 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:04:30 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Return the len of a t_list
int ft_len_cmd(t_cmd *head)
{
    int     i;
    t_cmd  *tmp;

    tmp = head;
    i = 0;
    while (tmp)
    {
        tmp = tmp->next_pipe;
        i++;
    }
    return (i);
}

//  Return the len of a t_list
int ft_len_list(t_list *head)
{
    int     i;
    t_list  *tmp;

    tmp = head;
    i = 0;
    while (tmp)
    {
        tmp = tmp->content;
        i++;
    }
    return (i);
}
