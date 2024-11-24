/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:27:39 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 20:13:59 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//										INCLUDES

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/includes/libft.h"

//										DEFINES

#define MAX_CMD_ARGS 10
#define TEMP_FILE_TEMPLATE "/tmp/heredoc_XXXXXX"

//										ENUMS

typedef enum e_ms_state
{
	e_shell_idle,
	e_shell_heredoc,
	e_shell_exec,
} e_ms_state;

typedef enum e_ms_token
{
	e_str,			// Chaine de caracteres
	e_pipe,			// |
	e_quote,			// '
	e_d_quote,			// "
	e_l_chevron,		// Redirection de l'entree de la commande
	e_r_chevron,		// Redirection de la sortie de la commande en ecrasant
	e_here_doc,		// Ouvre le here-doc
	e_appen,			// Rajoute le contenu a la fin d'un fichier sans ecraser
} e_ms_token;

//										STRUCTURES

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
	e_ms_state state;
	t_list	*env;
	t_cmd	*head;
	int		ret_value;
	int		state; // Correspond au state de mon shell -> 1 lecture de commande, 2 heredoc et 3 exec
} t_shell;

//										PROTOTYPES

//	BUILTINS

int ft_cd(t_shell *shell, t_cmd *cmd);
int ft_echo(t_shell *shell, t_cmd *cmd);
int ft_env(t_shell *shell);
int ft_exit(t_shell *shell, t_cmd *cmd);
int ft_export(t_shell *shell, t_cmd *cmd);
int ft_pwd(t_shell *shell);
int ft_unset(t_shell *shell, t_cmd *cmd);

// T_CMD CMDS

t_cmd	*ft_cmdnew(char *content);
void	ft_cmdadd_back(t_shell *shell, t_cmd *new);
void	ft_create_new_cmd(t_shell *shell, t_cmd *new);
t_cmd	*get_last_cmd_first_node(t_shell *shell);
//	UTILS

char	*get_env(t_shell *shell, char *name);

//	SIGNAUX

void	setup_signals(t_shell *shell);

//	EXEC

pid_t	fork_process();
void	create_pipe(int fd[2]);
char	*get_cmd(t_shell *shell, t_cmd *cmd);

#endif
