/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:23:23 by cwolf             #+#    #+#             */
/*   Updated: 2025/02/24 15:21:24 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int sig)
{
    //ft_printf("PID: %d\n", g_pid);
    if ((sig == SIGINT) && g_pid != 0)
    {
        // write(1, "bier", 5);
        // in_process(sig);
        ft_putchar_fd('\n', 1);
    }
    else
    {
        // write(1, "hier", 5);
        if (sig == SIGINT)
        {
            write(1, "\n", 1);
            rl_on_new_line();
            rl_replace_line("", 0);  
            rl_redisplay();
        }
        else if (sig == SIGQUIT)
        {
            (void)sig;
        }
    }
}

void sigchld_handler(int signum)
{
    // Warten auf alle beendeten Kindprozesse
    signum = signum + 0;
    while (waitpid(-1, NULL, WNOHANG) > 0)
        ;  // Solange es beendete Kindprozesse gibt, tue nichts, nur aufräumen
}

// void zombie_handler(void)
// {
//     struct sigaction sa_zombie;
//     memset(&sa_zombie, 0, sizeof(sigaction));
//     sa_zombie.sa_handler = SIG_DFL;
//     sa_zombie.sa_flags = SA_NOCLDWAIT;
//     sigaction(SIGCHLD, &sa_zombie, NULL);
    
// }

void setup_signals(void)
{
    
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigint_handler);
    rl_catch_signals = 0;
}
