/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:03 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 13:17:29 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	idx stands for index 
int	ft_strslashjoin(char *dest, char *str, char *env, int *idx)
{
	int			i;
	int			j;

	i = -1;
	(*idx)--;
	while (++(*idx) < (PATH_MAX - 1) && env[(*idx)] && env[(*idx)] != ':')
		dest[++i] = env[*idx];
	i++;
	dest[i++] = '/';
	j = -1;
	while (j < (PATH_MAX - 1) && str[j])
		dest[++i] = str[++j];
	dest[i] = '\0';
	return (0);
}

static char	*cmd_not_found(char *sample)
{
	ft_printf_fd(2, "%s : command not found\n", sample);
	return (NULL);
}

char	*find_cmd(t_shell *master, char *sample)
{
	char		*paths;
	char		path[PATH_MAX];
	int			i;
	int			len;

	paths = get_env("PATH", master);
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
