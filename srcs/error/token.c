/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 10:35:32 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/23 10:35:53 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_error_token(t_shell *master, t_token *token)
{
	master->ret_value = 1;
	printf("Error\n%s failed\n", token->str);
	return (1);
}
