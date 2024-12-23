/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_print_hex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrombez <ncrombez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:18:23 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/15 11:54:13 by ncrombez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(int fd, unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(fd, num / 16, format);
		ft_put_hex(fd, num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_fd_printchar((num + '0'), fd);
		else
		{
			if (format == 'x')
				ft_fd_printchar((num - 10 + 'a'), fd);
			if (format == 'X')
				ft_fd_printchar((num - 10 + 'A'), fd);
		}
	}
}

int	ft_fd_print_hex(int fd, unsigned int num, const char format)
{
	if (num == 0)
		return (write(2, "0", 1));
	else
		ft_put_hex(fd, num, format);
	return (ft_hex_len(num));
}
