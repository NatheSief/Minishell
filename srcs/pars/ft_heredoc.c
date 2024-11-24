/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:57:33 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 22:23:03 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	Generate the heredoc file name in function of the number of here doc I had
//		during the execution of the shell
char	*get_hd_name(void)
{
	static int	number;
	char		*value;
	char		*name;

	if (!number)
		return (NULL);
	value = ft_itoa(number);
	if (!value)
		return (NULL);
	name = ft_strjoin(TEMP_FILE_TEMPLATE, value);
	number++;
	free(value);
	return (name);
}

int	handle_heredoc(t_cmd *cmd)
{
	char	*name;
	
	name = get_hd_name();
	if (!name)
		name = get_hd_name();
	if (!name)
		return (1);
	
}