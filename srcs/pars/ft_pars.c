/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:49 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:34:10 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pars(t_shell *master, char *entry)
{
    char    **splitted;
    int     input;
    int     output;
    int     i;

    i = -1;
    input = -2;
    output = -2;
    if (checker(entry))
        return (1);
    if ((master->token = create_tkn_lst(entry)) == NULL)
    {
        free_token(splitted);
        return (1);
    }
    if (init_new_cmd(master, splitted[i], input, output))
    {
        free_cmd(master->command);
        free_token(master->token);
        return (1);
    }
}
