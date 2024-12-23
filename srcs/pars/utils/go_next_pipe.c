/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:43:48 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 14:50:33 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Skip all white space in-between actual char and next non-white-space char
//      in str
int	skip_white_space(char *str, int i)
{
	while (str[++i])
	{
		if (is_whitespace(str[i]))
			continue;
	}
	if (!str[i])
		return (-1);
	return (i);
}
