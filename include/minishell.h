/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:06:36 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/17 14:23:18 by phhofman         ###   ########.fr       */
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
void	print_tokens(t_list *tokens);

//execute
char	*execute(char *prompt, char *envp[]);
char	*read_prompt();
void	pipex(char *args[], char *envp[]);

// pipex_utils
char	*get_envp(char *name, char *envp[]);
char	*get_cmd_path(char *cmd, char *envp[]);
char	**get_paths(char *envp[]);
void	handle_error(char *error_msg, int exit_status);

// parse
void	print_baum(t_cmd *baum);
void print_ast(t_cmd *cmd, int depth);
t_cmd	*parse_cmd(t_list **list);
t_cmd	*parse_line(t_list **list);
t_cmd	*parse_block(t_list **list);
t_cmd	*parse_pipe(t_list	**liste);
t_cmd	*parse_exec(t_list **liste);
t_cmd	*parse_redir(t_list **list, t_cmd *cmd);

// tokens
t_token	*token_init(int type, char *value);
t_cmd	*exec_cmd_init(char **cmd_args);
t_cmd	*redir_cmd_init(t_cmd *cmd, char *file, int fd, int mode);
t_cmd	*pipe_cmd_init(t_cmd *left, t_cmd *right);
t_cmd	*seq_cmd_init(t_cmd *left, t_cmd *right);
t_cmd	*back_cmd_init(t_cmd *left);
t_list	*convert_prompt_to_list(char *buf);
int		get_token_type(char c);

// list
t_list	*convert_prompt_to_list(char *prompt);

#endif