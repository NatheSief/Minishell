/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nate <nate@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:57:32 by nate              #+#    #+#             */
/*   Updated: 2024/11/18 20:10:33 by nate             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



// Fonction pour avancer jusqu'à un caractère non séparateur
static char *advance_to_non_delim(char *str, const char *delim) {
    while (*str && ft_strchr(delim, (int)*str))
        str++;
    return (str);
}

char *my_strtok(char *str, const char *delim) {
    char		*token_start;
	static char	*next_token = NULL;

	if (str == NULL)
        str = next_token;
    if (str == NULL || *str == '\0')
	{
        next_token = NULL;
        return (NULL);
    }
    str = advance_to_non_delim(str, delim);
    if (*str == '\0')
	{
        next_token = NULL;
        return (NULL);
    }
    token_start = str;
    while (*str && !strchr(delim, *str))
        str++;
    if (*str)
	{
        *str = '\0';
        next_token = str + 1;
    }
	else
        next_token = NULL;
    return (token_start);
}

// void split_string(const char *str, const char *delim) {
//     char *token = my_strtok((char *)str, delim);
//     while (token != NULL) {
//         printf("Token: %s\n", token);
//         token = my_strtok(NULL, delim);
//     }
// }

// int main() {
//     const char *input = "Hello, world! This is a test.";
//     const char *delim = " ,.!";  // Séparateurs

//     split_string(input, delim);

//     return 0;
// }
