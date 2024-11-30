/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:56:09 by eunjiko           #+#    #+#             */
/*   Updated: 2022/10/13 16:01:19 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printp(unsigned long num, int	*len)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (num > 15)
		printp(num / 16, len);
	ft_putchar(hex[num % 16], len);
}
