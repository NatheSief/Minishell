/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:35:42 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:43:38 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *create_token(char *str)
{
    char    *tmp;
}

//  Add the tokens after each other and create the head list if I don't have
//      any token in the list
void    add_token_to_end(t_shell *master, t_token *new)
{
    t_token *tmp;

    tmp = master->token;
    if (!tmp)
        return (master->token = new, NULL);
    while (tmp->next_token)
        tmp = tmp->next_token;
    tmp->next_token = new;
}
