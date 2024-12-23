/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncrombez <ncrombez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:17:53 by nsiefert          #+#    #+#             */
/*   Updated: 2024/12/15 12:16:34 by ncrombez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fd_printchar(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_fd_formats(int fd, const char format, va_list args)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_fd_printchar(fd, va_arg(args, int));
	else if (format == 's')
		print_length += ft_fd_printstr(fd, va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_fd_print_ptr(fd, va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_fd_printnbr(fd, va_arg(args, int));
	else if (format == 'u')
		print_length += ft_fd_print_unsigned(fd, va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_fd_print_hex(fd, va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += ft_fd_printchar('%', fd);
	return (print_length);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_fd_formats(fd, str[i + 1], args);
			i++;
		}
		else
			print_length += ft_fd_printchar(str[i], fd);
		i++;
	}
	va_end(args);
	return (print_length);
}
