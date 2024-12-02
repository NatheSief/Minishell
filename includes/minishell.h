/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:42:27 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/02 11:07:17 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
/*                              INCLUDES                                      */
/* ************************************************************************** */

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
# include <limits.h>
# include <sys/stat.h>
# include "../libft/includes/libft.h"

/* ************************************************************************** */
/*                               DEFINES                                      */
/* ************************************************************************** */

# define TEMP_FILE_TEMPLATE "/tmp/heredoc_XXXXXX"
# define ERROR_MALLOC	1
#define PATH_MAX        4096	/* FROM LIMITS.H*/

/* ************************************************************************** */
/*                                ENUMS                                       */
/* ************************************************************************** */

//	Gestion de l'etat de mon shell pour gerer les signaux
//	-----------------------------------------------------
//	IDLE	==	Attente de commande
//	HEREDOC	==	heredoc
//	EXEC	==	Cmd execution
typedef enum e_ms_state
{
	e_shell_idle,
	e_shell_heredoc,
	e_shell_exec,
} e_ms_state;

//	Gestion de mes tokens
//	---------------------
//	STR			==	String without anything particular	
//	PIPE		==	Pipe in-between commands
//	L_CHEVRON	==	Input redirection, should be after the arguments, I can have
//						as much as I want to but I will only read the last one
//	R_CHEVRON	==	Output redirection, should create the files if they don't
//						exist, then only write in the last one
//	HERE_DOC	==	Create a temporary file then write into it the content of
//						the user here-doc. If multiple here-docs, you should
//						exec them all but only read the last one (function as
//						an input redirection)
//	APPEN		==	Same as the here-doc but for the ouput, and also write at
//						the end of the file, without over-writing in the file

# define INPUT 		1	//	"<"
# define OUPUT 		2	//	">"
# define HEREDOC 	3	//	"<<"
# define APPEN 		4	//	">>"
# define PIPE		5	//	"|"
# define CMD		6	//	"string"
# define ARGS		7	//	"string"

/* ************************************************************************** */
/*                              STRUCTURES                                    */
/* ************************************************************************** */

extern pid_t	g_signal_pid;

//  Structure COMMAND :
//      - cmd[3] is a char tab that contains :
//          cmd[0] - the command
//          cmd[1] - the options
//          cmd[2] - the arguments (stacked in one string)
//      - input contains the input fd
//      - output contains the output fd
//      - next_pipe is a pointer to the next command to exec after a pipe
typedef struct s_cmd
{
	char			**cmd;
	int				skipable;
	int				input;
	int				output;
	struct s_cmd	*next_pipe;
} t_cmd;

typedef struct s_token
{
	int				type;
	char        	*str;
	struct s_token	*next_token;
} t_token;

//  Structure SHELL :
//      - state is an enum that change in function of the shell state (cf enum)
//      - env contains all the env variables
//      - command is the head of the linked list of commands
//      - ret_value is the return value of the commands that I can display with
//          echo $?
typedef struct s_shell
{
	e_ms_state state;
	t_list	**env;
    t_token	**token;
	t_cmd	**command;
	int		input_fd;
	int		ret_value;
	int		fd[2];
} t_shell;

/* ************************************************************************** */
/*                              PROTOTYPES                                    */
/* ************************************************************************** */

//  INIT

int 	init_new_cmd(t_shell *master, char **cmd, int infile, int outfile);
int     init_shell(t_shell *master, char **envp);

//  REDIRECTIONS

int		get_in(t_shell *data, t_token *tmp, t_cmd *cmd);
int		get_out(t_token *tmp, t_cmd *cmd, t_shell *data);

//  SIGNALS

void    init_sig(t_shell *master);

//  PARSING

int ft_pars(t_shell *master, char *entry);

//  EXEC

int		ft_strslashjoin(char *dest, char *str, char *env, int *index);
char	*find_cmd(t_shell *master, char *sample, t_list *env);
int		here_doc(t_shell *master, char *word);
int		is_builtin(char *str);
void	child_process(t_shell *master, t_cmd *cmd, int *pip);
int		launch_builtin(t_shell *master, t_cmd *cmd);
int     ft_exec(t_shell *master);

//	ERROR

void	free_token(t_token	**token);
void	free_cmd(t_cmd	**command);
void	free_all(t_shell *master, char *err, int ext);

//  UTILS

int		ft_len_list(t_list *head);
int     ft_go_next(char *str, char c, int pos);
int     ft_go_next_non_white_space(char *str);

//  BUILTINS

int 	ft_cd(t_shell *master, t_cmd *cmd);
int 	ft_echo(t_shell *master, t_cmd *cmd);
int 	ft_env(t_shell *master);
int 	ft_exit(t_shell *master, t_cmd *cmd);
int 	ft_export(t_shell *master, t_cmd *cmd);
int 	ft_pwd(t_shell *master);
int 	ft_unset(t_shell *master, t_cmd *cmd);


#endif