/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:06:36 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/12 10:33:06 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "./token.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>


// utils
void	panic(char *error_msg);
void	print_string_array(char **prompt);
// char	**copy_split(char **split, int len);
// char	**get_cmd_args(char **prompt);

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

// tokens
t_cmd	*exec_cmd_init(char **cmd_args);
t_cmd	*redir_cmd_init(t_cmd *cmd, char *file, int fd, int mode);
void	get_token(char *buf);

// list
void	append_node(t_list **head, void *data);

// signals
void setup_signals(void);

#endif