/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:05:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/02/24 15:21:19 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void check_running_children(void)
{
    int status;
    pid_t pid;

    // Prüfe, ob noch Kindprozesse laufen
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        printf("1Kindprozess mit PID %d beendet, Status: %d\n", pid, WEXITSTATUS(status));
    }

    if (pid == 0)
    {
        printf("1Es gibt noch laufende Kindprozesse.\n");
    }
    else if (pid == -1)
    {
        printf("1Keine Kindprozesse mehr aktiv.\n");
    }
}

// static void restore_stdin(int original_stdin)
// {
//     // Stelle den ursprünglichen stdin File Descriptor wieder her
//     dup2(original_stdin, STDIN_FILENO);
//     close(original_stdin); // Schließe den temporären File-Descriptor
// }

void check_children()
{
    int status;
    pid_t pid = waitpid(-1, &status, WNOHANG);

    if (pid > 0)
        printf("2Es gibt noch laufende Kindprozesse (PID: %d)\n", pid);
    else
        printf("2Keine Kindprozesse mehr aktiv.\n");
}

char	*read_prompt()
{
	char	*prompt;
	char	*input;
	
	prompt = "🤏🐚\033[0;32m $ \033[0m";

	input = readline(prompt);
	add_history(input);

	return (input);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*input;
	t_list	*list;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	g_pid = 0;
	setup_signals();
	while (1)
	{
		input = read_prompt();
		if (!input)
		{
			ft_printf("exit");
			exit(EXIT_SUCCESS);
		}
		list = tokenizer(input);
		if (list)
		{
			// ft_lstiter(list, print_tokens);
			cmd = parse_cmd(&list);
			// print_ast(cmd, 0);
			if (fork_plus() == 0)
			{
				run(cmd, envp);
				exit(EXIT_SUCCESS);
			}
			// check_running_children();
			// check_children();
			// setup_signals();
			wait(NULL);
			// g_pid = 0;
		}
		free(input);
	}
	rl_clear_history();
	return (EXIT_SUCCESS);
}
