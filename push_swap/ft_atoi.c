/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:43:01 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/05 16:00:39 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_int(int check, const char *str)
{
	while (str[check])
	{
		if (str[check] < '0' || str[check] > '9')
			exit_from_err("is not integer");
		check++;
	}
}

int	ft_atoi(const char *str, int idx, long long sign, long long res)
{
	int	flag;

	flag = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	check_int(idx, str);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		flag = 0;
		res = res * 10 + str[idx] - '0';
		if (res < 0)
			return ((sign + 1) / -2);
		idx++;
	}
	if (res * sign > 2147483647 || res * \
		sign < -2147483648 || flag == 1)
		exit_from_err("is not integer");
	return ((int)(res * sign));
}
