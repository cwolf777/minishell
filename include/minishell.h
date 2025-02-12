/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:06:36 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/12 13:40:55 by phhofman         ###   ########.fr       */
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
char	**ft_split2(char const *s, char *delimiters);
void	panic(char *error_msg);
void	print_string_array(char **prompt);
char	*ft_char_to_str(char c);
void	print_list(t_list * list);
void	free_str_arr(char **arr);

//execute
char	*execute(char *prompt, char *envp[]);

// pipex_utils
char	*get_envp(char *name, char *envp[]);
char	*get_cmd_path(char *cmd, char *envp[]);
char	**get_paths(char *envp[]);
void	handle_error(char *error_msg, int exit_status);

// parse
char	*read_prompt();
void	pipex(char *args[], char *envp[]);

// tokens
t_cmd	*exec_cmd_init(char **cmd_args);
t_cmd	*redir_cmd_init(t_cmd *cmd, char *file, int fd, int mode);
t_cmd	*pipe_cmd_init(t_cmd *left, t_cmd *right);
t_cmd	*seq_cmd_init(t_cmd *left, t_cmd *right);
t_cmd	*back_cmd_init(t_cmd *left);
t_list	*convert_prompt_to_list(char *buf);

// list
t_list	*convert_prompt_to_list(char *prompt);

#endif