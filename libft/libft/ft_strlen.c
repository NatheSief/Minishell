/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:39:48 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 17:43:21 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strnlen(const char *s, size_t n)
{
	size_t len;

	len = 0;
	while (s[len] != '\0' && len < n)
		len++;
	return (len);
}

size_t	ft_strlen_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		continue;
	return (i);
}
