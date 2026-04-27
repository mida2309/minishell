# Minishell - As Beautiful as a Shell

*This project has been created as part of the 42 curriculum by mida.*

## Description
Minishell is a 42 school project consisting of the creation of a simple shell. It serves as a practical introduction to the inner workings of an operating system, specifically focusing on process management and file descriptors.

## Features
The program implements the following functionalities:
- Interactive prompt with command history.
- Execution of commands via absolute, relative paths, or the PATH variable.
- Built-in commands: echo (with -n), cd, pwd, export, unset, env, and exit.
- Management of single and double quotes.
- Redirections: <, >, >> and << (here-doc).
- Pipes (|) to connect multiple commands.
- Environment variable expansion ($VAR) and exit status handling ($?).
- Signal handling: ctrl-C, ctrl-D, and ctrl-\ (matches Bash behavior).

## Technical Requirements
- Language: C.
- Strict memory management: No leaks tolerated (excluding readline leaks).
- Compliance with the 42 Norm.
- No unexpected crashes (Segmentation faults, bus errors, etc.).

## Instructions
To compile the project, use the provided Makefile:
make

To run the shell:
./minishell

## Resources and AI Usage
This project involved the study of UNIX system calls such as fork, execve, waitpid, and pipe. In accordance with the 42 curriculum guidelines, AI tools were utilized for initial parser design and the generation of test cases. Every AI-generated suggestion was reviewed, tested, and verified against Bash behavior to ensure full technical understanding and compliance with the subject.

# Minishell - As Beautiful as a Shell

*Ce projet a été réalisé dans le cadre du cursus 42 par mida.*

## Description
Minishell est un projet de l'école 42 consistant à créer un shell simple. Il constitue une introduction pratique au fonctionnement interne des systèmes d'exploitation, en se concentrant particulièrement sur la gestion des processus et des descripteurs de fichiers.

## Fonctionnalités
Le programme implémente les fonctionnalités suivantes :
- Prompt interactif avec gestion de l'historique des commandes.
- Exécution de commandes via chemins absolus, relatifs ou la variable PATH.
- Commandes intégrées (built-ins) : echo (avec -n), cd, pwd, export, unset, env et exit.
- Gestion des guillemets simples (quotes) et doubles (double quotes).
- Redirections : <, >, >> et << (here-doc).
- Pipes (|) pour connecter plusieurs commandes.
- Expansion des variables d'environnement ($VAR) et gestion du statut de sortie ($?).
- Gestion des signaux : ctrl-C, ctrl-D et ctrl-\ (comportement identique à Bash).

## Exigences Techniques
- Langage : C.
- Gestion stricte de la mémoire : Aucune fuite tolérée (hors fuites liées à readline).
- Respect de la Norme 42.
- Absence de crash inattendu (Segmentation fault, bus error, etc.).

## Instructions
Pour compiler le projet, utilisez le Makefile fourni :
make

Pour lancer le shell :
./minishell

## Ressources et Utilisation de l'IA
Ce projet a nécessité l'étude des appels système UNIX tels que fork, execve, waitpid et pipe. Conformément aux directives du cursus 42, des outils d'IA ont été utilisés pour la conception initiale de la logique du parseur et la génération de tests. Chaque suggestion générée par IA a été revue, testée et vérifiée par rapport au comportement de Bash afin de garantir une compréhension technique totale et la conformité au sujet.

