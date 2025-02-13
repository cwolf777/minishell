/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:23:23 by cwolf             #+#    #+#             */
/*   Updated: 2025/02/13 11:53:27 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int sig)
{
    (void)sig;
    if (!g_in_child)
    {
    write(1, "\n", 1);
        rl_on_new_line();
        rl_replace_line("", 0);  
        rl_redisplay();
    }
}

void sigquit_handler(int sig)
{
    (void)sig;
}

void setup_signals(void)
{
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    rl_catch_signals = 0; //darf ich das benutzten?
}