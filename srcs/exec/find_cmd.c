/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:03 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:06:04 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strslashjoin(char *dest, char *str, char *env, int *index)
{
	int			i;
	int			j;

	i = -1;
	while (index[++i] < (PATH_MAX - 1) && env[(index[i])] && env[(index[i])] != ':')
		dest[i++] = env[index[i]];
	i++;
	dest[i++] = '/';
	j = -1;
	while (j < (PATH_MAX - 1) && str[j])
		dest[++i] = str[++j];
	dest[i] = '\0';
	return (0);
}

static char	*create_paths(t_list *env, int len)
{
	t_list	*tmp;

	tmp = env;
	while (len--)
	{
		if (ft_strncmp((char *)tmp->content, "PATH=", 5) == 0)
			return ((char *)(tmp->content) + 5);
		tmp = tmp->next;
	}
	return (NULL);
}

static char	*cmd_not_found(char *sample)
{
	write(2, sample, ft_strlen(sample));
	write(2, " : command not found\n", 21);
	return (NULL);
}

char	*find_cmd(t_shell *master, char *sample, t_list *env)
{
	char		*paths;
	char		path[PATH_MAX];
	int			i;
	int			len;

	paths = create_paths(env, ft_len_list(env));
	if (!paths || ft_strlen(sample) > PATH_MAX / 2)
		return (cmd_not_found(sample));
	i = 0;
	len = ft_strlen(paths);
	while (i < len)
	{
		ft_strslashjoin(path, sample, paths, &i);
		if (access(path, F_OK) == 0)
		{
			sample = ft_strdup(path);
			if (!sample)
			{
				print_error(ERROR_MALLOC);
				master->ret_value = -1;
			}
			return (sample);
		}
	}
	return (cmd_not_found(sample));
}
