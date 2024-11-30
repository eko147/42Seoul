/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 23:50:57 by eunjiko           #+#    #+#             */
/*   Updated: 2022/10/12 21:37:05 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	idx;

	idx = 0;
	if (!str)
		return (ft_putstr("(null)", len));
	while (str[idx])
		ft_putchar(str[idx++], len);
}
