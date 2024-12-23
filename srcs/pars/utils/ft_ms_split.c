/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:23:12 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 18:46:20 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Get the count of elements I have in my string
static int ft_count_elem(char *entry)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (entry[++i])
	{
		if (entry[i] == '\'')
			i = ft_go_next(entry, '\'', i);
		if (entry[i] == '"')
			i = ft_go_next(entry, '"', i);
		else if (entry[i] == ' ')
		{
			count ++;
			i = ft_go_next_non_white_space(entry, i);
		}
	}
	return (count);
}

static int	get_len_elem(char *str, int pos, int len)
{
	int		i;
	int		start;

	i = -1;
	start = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
			i = ft_go_next(str, '\'', i);
		if (str[i] == '"')
			i = ft_go_next(str, '"', i);
		else if (str[i] == ' ' && --pos)
		{
			i = ft_go_next_non_white_space(str, i);
			start = i;
		}
	}
	if (len)
		return (i - start);
	return (start);
}

char	**ft_ms_split(char *entry)
{
	char	**tab;
	int		num_elem;
	int		i;

	i = -1;
	num_elem = ft_count_elem(entry);
	tab = (char **)malloc(sizeof(char *) * num_elem);
	if (!tab)
		return (NULL);
	while (tab[++i])
	{
		tab[i] = (char *)malloc(sizeof(char) * get_len_elem(entry, i, 1));
		if (!tab[i])
			return (free_tab((void **)tab), NULL);
		ft_strlcpy(tab[i], entry + get_len_elem(entry, i, 0), get_len_elem(entry, i, 1));
	}
	return (tab);
}
