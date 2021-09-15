#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_command
{
    char *command_name;
    char *command_option;
    char *command_argument;
    char *env_var_list;

} t_command;

typedef struct s_global
{
    int return_code;
}               t_global;

#endif