/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:35:19 by nsiefert          #+#    #+#             */
/*   Updated: 2024/11/18 20:18:33 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	char	*to_return;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(1));
	total = nmemb * size;
	if (total / nmemb != size && total / size != nmemb)
		return (NULL);
	to_return = (char *)malloc(total);
	if (to_return == NULL)
		to_return = NULL;
	else
		ft_bzero(to_return, total);
	return (to_return);
}
