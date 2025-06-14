🐚 **minishell**
This repository contains a solution to the minishell project from the third circle of the 42 school curriculum.
It is a simplified Unix shell, focused on understanding terminal behavior, process handling, environment management, and memory control.


🚀 **Project Overview**
minishell replicates core functionalities of a Unix shell, allowing users to execute commands, navigate directories, manage environment variables, and handle pipes and redirections — all within a custom-built execution environment.

This implementation emphasizes:

Process creation and management (fork, execve, wait)

Parsing and tokenizing input with quote/context awareness

Redirects (>, >>, <, <<) and pipe (|) handling

Signal handling (SIGINT, SIGQUIT)

Environment variable support and export/unset logic

Clean memory handling through a custom garbage collector


🧠 **Custom Garbage Collector**
To avoid memory leaks during complex command parsing and execution, this project includes a bespoke garbage collector:

Tracks and frees dynamically allocated memory

Ensures exception-safe cleanup even on early exits

Simplifies memory management across multiple execution stages


🔧 **Supported Features**
Built-in commands: cd, echo, env, exit, export, pwd, unset
Quoted strings, escape characters, and environment expansion
Multiple pipes and chained commands
I/O redirection with file descriptor management
Signal responsiveness (e.g., Ctrl+C interrupt)
Exit status propagation
