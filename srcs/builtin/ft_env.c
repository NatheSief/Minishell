/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:14:07 by nate              #+#    #+#             */
/*   Updated: 2024/12/20 16:15:52 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_env(t_shell *master)
{
	t_list *tmp;

	tmp = master->env;
	while (tmp->next)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	master->ret_value = 0;
	return (0);
}

