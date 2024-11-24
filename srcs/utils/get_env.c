/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:36:19 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/18 11:48:58 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env(t_shell *shell, char *name)
{
	char	*to_ret;
	t_list	*tmp;

	tmp = shell->env;
	while (tmp)
	{
		if (!ft_strncmp((char *)tmp->content, name, ft_strlen(name)))
		{
			to_ret = ft_strdup((char *)tmp->content + ft_strlen(name) + 1);
			if (!to_ret)
				return (NULL);
			return (to_ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
