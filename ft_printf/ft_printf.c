/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:59:50 by eunjiko           #+#    #+#             */
/*   Updated: 2022/10/13 16:54:40 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse(va_list ap, char data_type, int *len)
{
	if (data_type == 'c')
		ft_putchar(va_arg(ap, int), len);
	else if (data_type == 'd' || data_type == 'i')
		ft_putnbr(va_arg(ap, int), len);
	else if (data_type == 's')
		ft_putstr(va_arg(ap, char *), len);
	else if (data_type == 'p')
	{
		ft_putstr("0x", len);
		printp(va_arg(ap, unsigned long), len);
	}
	else if (data_type == 'u' || data_type == 'x' || data_type == 'X')
		printxu(va_arg(ap, unsigned int), len, data_type);
	else if (data_type == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int		idx;
	int		len;
	va_list	ap;

	va_start(ap, format);
	if (!format)
		return (-1);
	idx = 0;
	len = 0;
	while (format[idx] != '\0')
	{
		if (format[idx] == '%' && format[idx + 1])
		{
			parse(ap, format[idx + 1], &len);
			idx++;
		}
		else
		{
			write(1, &format[idx], 1);
			len++;
		}
		idx++;
	}
	va_end(ap);
	return (len);
}
