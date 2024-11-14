/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:14:07 by nate              #+#    #+#             */
/*   Updated: 2024/11/09 14:16:55 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int ft_env(t_shell *shell)
{
	t_list *tmp;

	tmp = shell->env;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	shell->ret_value = 0;
	return (0);
}