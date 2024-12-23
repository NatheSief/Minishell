/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:34:28 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 18:46:49 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void get_tkn_type(t_token *tmp, char *str)
{
    if (str[0] == '<')
    {
        if (str[1] == '<')
            tmp->type = HEREDOC;
        else
            tmp->type = INPUT;
    }
    else if (str[0] == '>')
    {
        if (str[1] == '>')
            tmp->type = APPEN;
        else
            tmp->type = OUTPUT;
    }
    else if (str[0] == '|')
        tmp->type = PIPE;
    else
        tmp->type = STRING;
}

int create_tkn_lst(t_shell *master, char **entry)
{
    t_token *tmp;
    int     i;

    i = -1;
    while (entry[++i])
    {
        tmp = ft_tknnew();
        if (!tmp)
            return (1);
        get_tkn_type(tmp, entry[i]);
        tmp->str = ft_strdup(entry[i]);
        if (!tmp->str)
            return (free(tmp), 1);
        ft_tknadd_back(master->token, tmp);
    }
    return (0);
}

int tokenizator(t_shell *master, char *str)
{
    char **tab;

    tab = ft_ms_split(str);
    if (!tab)
        return (1);
    if (create_tkn_lst(master, tab))
        return (free_tab((void**)tab), free_token(master->token), 1);
    free_tab((void**)tab);
    if (check_token(master))
        return (free_token(master->token), 1);
    if (fill_cmd_struct(master))
        return (free_token(master->token), 1);
    return (0);
}
