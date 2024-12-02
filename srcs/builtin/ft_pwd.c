/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:23 by nate              #+#    #+#             */
/*   Updated: 2024/11/30 16:37:11 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_shell *master)
{
	char *buff;
	char *size;

	buff = NULL;
	buff = getcwd(buff, size);
	if (!buff)
	{
		shell->ret_value = 1;
		return (1);
	}
	printf("%s\n", buff);
	free(buff);
	shell->ret_value = 0;
	return (0);
}