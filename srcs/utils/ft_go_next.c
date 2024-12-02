/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:59:36 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 00:16:36 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Function that allows me to go to the next occurence of a character in the
//      the string
int ft_go_next(char *str, char c, int pos)
{
    int i;

    i = pos;
    while (str[++i])
    {
        if (str[i] == c)
            return (i);
    }
    return (0);
}

//  Function that skips all the white spaces at the beggining of a string
int ft_go_next_non_white_space(char *str)
{
    int i;

    i = 0;
    while (str[++i])
    {
        if (!ft_is_white_space(str[i]))
            return (i);
    }
    return (0);
}
