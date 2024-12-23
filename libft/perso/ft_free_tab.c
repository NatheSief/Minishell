/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 14:54:24 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/15 14:55:19 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "perso.h"

//  Free a 2 dimensions tab of pointers
void    free_tab(void   **tab)
{
    int i;

    i = -1;
    while (tab[++i])
        free(tab[i]);
    free(tab);
}
