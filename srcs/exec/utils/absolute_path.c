/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   absolute_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:54:57 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 15:13:17 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	absolute_path(__attribute__((unused))t_shell *master, char *cmd, \
	char **path)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (1);
	pwd = ft_strjoin_free_s1(pwd, cmd);
	if (!pwd)
		return (1);
	*path = ft_strdup(pwd);
	free(pwd);
	return (0);
}
