/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printxu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:52:28 by eunjiko           #+#    #+#             */
/*   Updated: 2022/10/13 16:57:55 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_x(unsigned int num, int *len)
{
	char	*x;

	x = "0123456789abcdef";
	if (num > 15)
		flag_x(num / 16, len);
	ft_putchar(x[num % 16], len);
}

void	flag_uperx(unsigned int num, int *len)
{
	char	*uper_x;

	uper_x = "0123456789ABCDEF";
	if (num > 15)
		flag_uperx(num / 16, len);
	ft_putchar(uper_x[num % 16], len);
}

void	flag_u(unsigned int num, int	*len)
{
	char	*u;

	u = "0123456789";
	if (num > 9)
		flag_u(num / 10, len);
	ft_putchar(u[num % 10], len);
}

void	printxu(unsigned int num, int	*len, char flag)
{
	if (flag == 'X')
		flag_uperx(num, len);
	else if (flag == 'x')
		flag_x(num, len);
	else if (flag == 'u')
		flag_u(num, len);
}
