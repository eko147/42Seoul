/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:36:38 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/27 06:56:56 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raise_b_c_part(t_info	*info, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		rrr(info);
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		rra(info, 0);
		ra--;
	}
	while (rb > 0)
	{
		rrb(info, 0);
		rb--;
	}
}

static void	devide_b_to_a(t_info *info, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (info->pv1 > info->b_stack->value)
		{
			rb(info, 0);
			info->rb++;
		}
		else
		{
			if (info->pv2 <= info->b_stack->value)
				pa(info);
			else
			{
				pa(info);
				ra(info, 0);
				info->ra++;
			}
			info->pa++;
		}
		i++;
	}
}

void	b_to_a(t_info *info, int size)
{
	int	rb;
	int	pa;
	int	ra;
	int	*array;

	if (size <= 3)
		return (hard_sort_for_b(info, size));
	array = set_int_arr_for_sort(info->b_stack, size);
	bubblesort(array, size);
	info->pv1 = array[size / 3];
	info->pv2 = array[size * 2 / 3];
	free(array);
	info->rb = 0;
	info->pa = 0;
	info->ra = 0;
	devide_b_to_a(info, size);
	rb = info->rb;
	pa = info->pa;
	ra = info->ra;
	a_to_b(info, pa - ra);
	raise_b_c_part(info, ra, rb);
	a_to_b(info, ra);
	b_to_a(info, rb);
}
