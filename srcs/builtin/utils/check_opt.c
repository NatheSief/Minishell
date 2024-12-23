/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:17:26 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/20 15:20:07 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_opt(char *lst_opt, char flag)
{
    int i;

    i = -1;
    while (lst_opt[++i])
    {
        if (lst_opt[i] != flag)
            return (1);
    }
    return (0);
}
