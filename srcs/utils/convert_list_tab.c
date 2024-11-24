/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_list_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nathe <nsiefert@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:01:58 by Nathe             #+#    #+#             */
/*   Updated: 2024/11/14 14:09:02 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Convert a t_list into a char tab
char	**convert_list_tab(t_list *head)
{
	char	**to_return;
	int		size;
	t_list	*tmp;
	int		i;

	size = ft_lstsize(&head);
	to_return = malloc(sizeof(char*) * size + 1);
	if (!to_return)
		return (NULL);
	tmp = head;
	i = -1;
	while (tmp)
	{
		to_return[++i] = ft_strdup((char *)tmp->content, \
			ft_strlen((char *)tmp->content)));
		tmp = tmp->next;
	}
	to_return[-1] = NULL;
	return (to_return);
}

