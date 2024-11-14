/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:27:39 by nate              #+#    #+#             */
/*   Updated: 2024/11/13 19:15:02 by Nathe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

typedef struct s_cmd
{
	char			*cmd[3];
	int				input;
	int				output;
	struct s_cmd	*next_pipe;
	struct s_cmd	*next_cmd;
} t_cmd;

typedef struct s_shell
{
	t_list	*env;
	t_cmd	*head;
	int		ret_value;
} t_shell;

int ft_cd(t_shell *shell, t_cmd *cmd);
int ft_echo(t_shell *shell, t_cmd *cmd);
int ft_env(t_shell *shell);
int ft_exit(t_shell *shell);
int ft_export(t_shell *shell, t_cmd *cmd);
int ft_pwd(t_shell *shell);
int ft_unset(t_shell *shell, t_cmd *cmd);

t_cmd	*ft_cmdnew(char *content);
void	ft_cmdadd_back(t_shell *shell, t_cmd *new);
void	ft_create_new_cmd(t_shell *shell, t_cmd *new);
#endif
