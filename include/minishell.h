/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:06:36 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/10 11:38:02 by phhofman         ###   ########.fr       */
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