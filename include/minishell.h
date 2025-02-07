/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:06:36 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/07 15:45:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>


typedef enum e_token_type{
	CMD,
	REDIR,
	PIPE,
	SEMI,
	BACK,
	ENV,
}	t_token_type;

typedef struct	s_redir
{
	int		type;
	char	*file;
	int		mode;		// O_WRONLY | O_CREATE
	int		fd;			// STDIN | STDOUT
}			t_redir;

typedef struct	s_cmd
{
	int		type;
	char	**cmd_args;	// ["cat", "-e", "Makefile", NULL];
}			t_cmd;

//execute
char	*execute(char *prompt, char *envp[]);
char	**ft_split2(char const *s, char *delimiters);

// pipex_utils
char	*get_envp(char *name, char *envp[]);
char	*get_cmd_path(char *cmd, char *envp[]);
char	**get_paths(char *envp[]);
void	free_split(char **split);
void	handle_error(char *error_msg, int exit_status);

// parse
char	*read_prompt();
void	pipex(char *args[], char *envp[]);

// list
void	append_node(t_list **head, void *data);

// trash
void	print_prompt(char **prompt);
char	**copy_split(char **split, int len);
char	**get_cmd_args(char **prompt);
#endif