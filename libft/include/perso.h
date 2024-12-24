/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perso.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:02:38 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 15:22:19 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERSO_H
# define PERSO_H

# include "libft.h"

int	    ft_countchar(char *str, char c);
int     ft_tabsize(char **tab);
void    free_tab(void   **tab);
void    print_tab(char **tab);
int     is_whitespace(char c);

#endif 