#include "minishell.h"

char	*add_to_str(char *str, int index, char *expanded)
{
	char	*to_ret;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = -1;
	size = ft_strlen(str) + ft_strlen(expanded) + 3;
	size -= ft_get_next_char(str, index, ' ');
	to_ret = malloc(sizeof(char) * size);
	if (!to_ret)
		return (NULL);
	while (++i < ft_strlen(to_ret))
	{
		if (i < index)
			to_ret[i] = str[i];
		else if (expanded[++j])
			to_ret[i] = expanded[j];
		else
			to_ret[i] = str[i - j + 1];
	}
	return (to_ret);
}

// Fonction pour remplacer les variables d'environnement dans une chaîne
int *expand_variable(t_shell *shell, const char *str)
{
    char *expanded;
	int			i;

	expanded = NULL;
	i = -1;
	while (str[++i])
	{
    	if (str[i] == '$') 
		{
    	    if (!ft_strncmp(str, "$?", 2))
				expanded = ft_itoa(shell->ret_value);
    	    else
			{
    	        if (get_env(shell, str + 1))
    	            expanded = ft_strdup(get_env(shell, str + 1));
    	    }
			str = add_to_str(str, i, expanded);
			if (!str)
			{
				free(expanded);
				return (1);
			}
		}
	}
	return (0);
}
