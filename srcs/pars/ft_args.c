#include "minishell.h"

// Fonction pour ajouter les arguments et faire l'expansion des variables
void parse_arguments(char *token, t_cmd *cmd, int *arg_count) {
    cmd->cmd[*arg_count] = expand_variable(token);  // Expansion des variables d'environnement
    (*arg_count)++;
}
