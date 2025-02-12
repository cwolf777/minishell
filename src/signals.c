/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:23:23 by cwolf             #+#    #+#             */
/*   Updated: 2025/02/12 12:31:59 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int sig)
{
    (void)sig;
    // pid_t pid = getpid();
    pid_t pgid = getpgrp();
    pid_t terminal_pgrp = tcgetpgrp(STDIN_FILENO);
    
    if (pgid == terminal_pgrp)  // Stelle sicher, dass nur der Hauptprozess reagiert
    {
        ft_printf("test");
        write(1, "\n", 1);  // Neue Zeile ausgeben
        rl_on_new_line();    // Cursor in neue Zeile setzen
        rl_replace_line("", 0);  // Eingabezeile löschen
        rl_redisplay();      // Prompt neu anzeigen
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
    rl_catch_signals = 0;
}