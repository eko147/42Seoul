/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:52:29 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/04 21:37:06 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*set_int_arr_for_sort(t_list	*list, int size)
{
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		exit(1);
	i = 0;
	while (i < size)
	{
		arr[i] = list->value;
		list = list->next;
		i++;
	}
	return (arr);
}

void	hard_sort(t_info *info)
{
	int	fst;
	int	scd;
	int	thd;

	fst = info->a_stack->value;
	scd = info->a_stack->next->value;
	thd = info->a_stack->next->next->value;
	if (fst < scd && scd > thd && fst < thd)
	{
		rra(info, 0);
		sa(info, 0);
	}
	else if (fst < scd && scd > thd && fst > thd)
		rra(info, 0);
	else if (fst > scd && scd < thd && fst < thd)
		sa(info, 0);
	else if (fst > scd && scd > thd && fst > thd)
	{
		ra(info, 0);
		sa(info, 0);
	}
	else if (fst > scd && scd < thd && fst > thd)
		ra(info, 0);
	print_oper_list(info->oper_list);
}
