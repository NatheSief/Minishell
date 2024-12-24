/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:53:26 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 13:43:17 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//  Get the value associated to the 'str' in the env
char	*get_env(char *str, t_shell *master)
{
	t_list *tmp;

	tmp = *master->env;
	while (tmp)
	{
		if (!ft_strncmp((const char *)tmp->content, str, \
        ft_strlen((char *)tmp->content)))
		{
			if (*((char*)tmp->content + ft_strlen((char *)tmp->content) + 1) \
            == '=')
				return (tmp->content + ft_strlen((char *)tmp->content) + 2);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

//  Change the value of a field in the env
void	change_env(t_shell *master, char *field, char *value)
{
    t_list  *tmp;
    char    *niquetoi;

    niquetoi = NULL;
    tmp = *master->env;
    while (tmp)
    {
        if (!ft_strncmp((const char *)tmp->content, field, ft_strlen(field)))
        {
            if (*(char *)(tmp->content + ft_strlen(field) + 1) == '=')
            {
                free(tmp->content);
                tmp->content = ft_strjoin(field, "=");
                niquetoi = ft_strjoin((char *)tmp->content, value);
                free(tmp->content);
                tmp->content = (void *)niquetoi;
                return ;
            }
        }
        tmp = tmp->next;
    }
    niquetoi = ft_strjoin_free_s1(niquetoi, field);
    niquetoi = ft_strjoin_free_s1(niquetoi, "=");
    niquetoi = ft_strjoin_free_s1(niquetoi, value);
    add_env(master, niquetoi);
}

int add_env(t_shell *master, char *str)
{
    t_list  *new;

    new = ft_lstnew((void *)str);
    if (!new)
        return (1);
    ft_lstadd_back(master->env, new);
    return (0);
}
