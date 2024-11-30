/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:04:28 by eunjiko           #+#    #+#             */
/*   Updated: 2023/01/15 21:23:44 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int			idx;
	long long	sign;
	long long	res;

	idx = 0;
	sign = 1;
	res = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		res = res * 10 + str[idx] - '0';
		if (res < 0)
			return ((sign + 1) / -2);
		idx++;
	}
	return ((int)(res * sign));
}

void	print_pid(int pid)
{
	char	temp;

	if (pid / 10 == 0)
	{
		temp = pid + '0';
		write(1, &temp, 1);
		return ;
	}
	print_pid(pid / 10);
	temp = pid % 10 + '0';
	write(1, &temp, 1);
}
