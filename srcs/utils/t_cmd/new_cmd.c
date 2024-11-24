/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:04:46 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/14 20:21:19 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_opt(char **tab, char *str)
{
	char	*ret_str;
	int		i;

	i = 0;
	while (tab[++i] && ft_strncmp(tab[i], "-", 1))
	{
		ret_str = ft_strjoin_free(ret_str, tab[i] + 1);
		if (!ret_str)
			return (NULL);
	}
	return (ret_str);
}

char	*get_cmd(char **tab, char *str)
{
	char	*ret_str;

	ret_str = ft_strdup(tab[0]);
	if (!ret_str)
		return (NULL);
	return (ret_str);
}

char	**split_cmd(char *str)
{
	char	*tab[3];
	char	**splitted_cmd;

	splitted_cmd = ft_split(str, ' ');\
	if (!splitted_cmd)
		return (1);
	tab[0] = get_cmd(splitted_cmd, str);
	tab[1] = get_opt(splitted_cmd, str);
	tab[2] = get_flags(splitted_cmd, str);
	if (!tab[0][0] || !tab[1][0] || !tab[2][0])
		return (1);
	return (0);
}

t_cmd	*new_cmd(t_cmd *cmd, char *str)
{
	cmd->next_cmd = NULL;
	cmd->next_pipe = NULL;
	if (split_cmd(str))
		return (1);
	return (0);
}

int	add_cmd(t_shell *shell, char **tab)
{
	t_cmd	*tmp;
	int		i;

	tmp = shell->head;
	while (tmp)
		tmp = tmp->next_cmd;
	tmp->next_cmd = new_cmd(tab[0]);
	if (!tmp->next_cmd)
		return (!1);
	i = 0;
	tmp = tmp->next_cmd;
	while (tab[++i)
	{
		tmp->next_pipe = new_cmd(tab[i]);
		if (!tmp->next_pipe)
			return (1);
		tmp = tmp->next_pipe;
	}
	return (0);
}
