/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:18:20 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/24 15:14:27 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str)
{
	if (str)
		ft_printf_fd(2, "Error\n %s", str);
}

// static int	do_i_need_to_interpret_that_shit(char *str, int idx)
// {
// 	int i ;
// 	int	mod;

// 	mod = 0;
// 	i = -1;
// 	while (str[++i] && i < idx)
// 	{
// 		if (str[i] == '\\')
// 			i++;
// 		else if (str[i] == '"' && mod == 0 )
// 			mod = 1;
// 		else if (str[i] == '"' && mod == 1)
// 			mod = 0;
// 		else if (str[i] == '\'' && mod == 0)
// 			mod = 2;
// 		else if (str[i] == '\'' && mod == 2)
// 			mod = 0;
// 	}
// 	if (i != idx || mod == 2)
// 		return (0);
// 	return (1);
// }

//	Expand
int	replace_dollar(t_shell *master, char *str)
{
// 	int		i;
// 	char	*buff;

// 	i = -1;
// 	buff = NULL;
// 	while (str[++i])
// 	{
// 		if (str[i] == '$')
// 		{
// 			if (do_i_need_to_interpret_that_shit(str, i))
// 			{
// 				buff = ft_strndup(str, i - 1);
// 				buff = ft_strjoin_free_s1(buff, get_env(str[i], master));
// 			}

// 		}
// 	}
// }
	(void)master;
	(void)str;
	return (0);
}