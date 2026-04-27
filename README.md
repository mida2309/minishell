# 🐚 Minishell - As Beautiful as a Shell

[cite_start] *This project has been created as part of the 42 curriculum by <mida>.* [cite: 294]

---

## 📝 Project Overview
[cite_start]**Minishell** is a minimalist implementation of a Bash shell. [cite: 154, 155] [cite_start]The core of this project is to recreate the experience of communicating with a computer via an interactive command-line interface, similar to the early days of IT. [cite: 165, 166]

[cite_start]This project provides a deep dive into **processes**, **file descriptors**, and **system calls** in C. [cite: 156, 170]

---

## 🚀 Key Features

### 🔹 Command Execution & History
- [cite_start]**Prompt Display**: A functional prompt waiting for new commands. [cite: 246]
- [cite_start]**History**: Integration of a working command history. [cite: 247]
- [cite_start]**Path Resolution**: Launches executables based on the `PATH` variable or absolute/relative paths. [cite: 248]

### 🔹 Built-in Commands
The shell implements the following essential built-ins:
- [cite_start]`echo` (with `-n` option) [cite: 276]
- [cite_start]`cd` (relative or absolute path) [cite: 277]
- [cite_start]`pwd`, `export`, `unset`, `env`, `exit` [cite: 278, 279, 280, 281, 282]

### 🔹 Redirections & Pipes
- [cite_start]**Redirections**: Handles `<` (input), `>` (output), `>>` (append), and `<<` (here-doc with delimiter). [cite: 262, 263, 264, 266]
- [cite_start]**Pipes**: Implements `|` to connect the output of one command to the input of the next. [cite: 267]

### 🔹 Environment & Logic
- [cite_start]**Variable Expansion**: Handles `$` for environment variables and `$?` for the last exit status. [cite: 268, 269]
- [cite_start]**Quote Management**: Handles single `'` (no interpretation) and double `"` (interprets `$`). [cite: 259, 260]
- [cite_start]**Signals**: Native behavior for `ctrl-C` (new prompt), `ctrl-D` (exit), and `ctrl-\` (do nothing). [cite: 272, 273, 274]

---

## 🛠️ Instructions

### Compilation
[cite_start]The project uses a **Makefile** with the mandatory flags `-Wall -Wextra -Werror`. [cite: 176]

```bash
# Compile the program
make

# Clean objects
make clean

# Full clean
make fclean

# Recompile
make re


