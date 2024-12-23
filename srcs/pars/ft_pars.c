/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:49 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 19:41:59 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int  ft_pipe(char *str)
{
	int mod;
	int i;

	i = -1;
	mod = 0;
	while (str[++i])
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '"' && !mod)
			mod = 1;
		else if (str[i] == '"' && mod == 1)
			mod = 0;
		else if (str[i] == '"' && !mod)
			mod = 1;
		else if (str[i] == '\'' && !mod)
			mod = 2;
		else if (str[i] == '\'' && mod == 2)
			mod = 0;
		else if (str[i] == '|' && !mod && skip_white_space(str, i) >= 0)
			i = skip_white_space(str, i);
		else if (skip_white_space(str, i) == -1)
			return (1);
	}
	return (0);
}

static int  ft_dquotes(char *str)
{
	int mod;
	int i;

	i = -1;
	mod = 0;
	while (str[++i])
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '"' && !mod)
			mod = 1;
		else if (str[i] == '"' && mod == 1)
			mod = 0;
		else if (str[i] == '"' && !mod)
			mod = 1;
		else if (str[i] == '\'' && !mod)
			mod = 2;
		else if (str[i] == '\'' && mod == 2)
			mod = 0;
	}
	return (mod);
}

static int  ft_quote(char *str)
{
	int mod;
	int i;

	i = -1;
	mod = 0;
	while (str[++i])
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '"' && !mod)
			mod = 1;
		else if (str[i] == '"' && mod == 1)
			mod = 0;
		else if (str[i] == '"' && !mod)
			mod = 1;
		else if (str[i] == '\'' && !mod)
			mod = 2;
		else if (str[i] == '\'' && mod == 2)
			mod = 0;
	}
	return (mod);
}

static int  checker(char *str)
{
	int check;

	check = 0;
	check += ft_pipe(str) + ft_dquotes(str) + ft_quote(str);
	return (check);
}

int ft_pars(t_shell *master, char *entry)
{
	char	**splitted;

	if (checker(entry))
		return (1);
    splitted = ft_ms_split(entry);
	if (splitted == NULL)
		return (1);
	if (create_tkn_lst(master, splitted))
		return (free_tab((void **)splitted), 1);
	return (free_tab((void **)splitted), 0);
}
