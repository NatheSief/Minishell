/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:25:11 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 20:10:33 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	get the pos of the next occurence of c in the string from id
int	ft_get_next_char(char *str, int id, char c)
{
	int	i;

	i = id;
	while (str[i++] && str[i] != c)
		continue;
	if (i == (int)ft_strlen(str))
		return (0);
	return (i - id);
}
