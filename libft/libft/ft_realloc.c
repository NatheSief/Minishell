/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:03:56 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 20:10:33 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	realloc : Alloc a new size then move 
void	*ft_realloc(void *ptr, int new_size)
{
	void	*new;

	new = ft_calloc(new_size, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, ptr, ft_strlen((char *)ptr));
	free(ptr);
	return (new);
}
