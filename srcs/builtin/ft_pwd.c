/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:17:23 by nate              #+#    #+#             */
/*   Updated: 2024/12/20 16:32:07 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_pwd(t_shell *master)
{
    char *buff;

	buff = NULL;
    if (getcwd(buff, 0) == NULL)
    {
        printf("bash: pwd: error retrieving current directory\n");
        free(buff);
        master->ret_value = 1;
        return (1);
    }
    printf("%s\n", buff);
    free(buff);
    master->ret_value = 0;
    return (0);
}
