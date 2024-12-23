/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:17:45 by nsiefert          #+#    #+#             */
/*   Updated: 2024/05/04 12:19:17 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fd_putstr(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

int	ft_fd_printstr(int fd, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_fd_putstr(2, "(null)");
		return (6);
	}
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_fd_printnbr(int fd, int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_fd_printstr(fd, num);
	free(num);
	return (len);
}

int	ft_fd_printpercent(int fd)
{
	write(fd, "%", 1);
	return (1);
}
