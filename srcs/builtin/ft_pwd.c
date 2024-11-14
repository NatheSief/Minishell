/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:23 by nate              #+#    #+#             */
/*   Updated: 2024/11/09 14:18:00 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_exec.h"

int ft_pwd(t_shell *shell)
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