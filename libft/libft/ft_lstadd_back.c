/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:36:00 by nsiefert          #+#    #+#             */
/*   Updated: 2024/11/18 20:18:33 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tempo;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tempo = *lst;
	while (tempo->next != NULL)
		tempo = tempo->next;
	tempo->next = new;
}
