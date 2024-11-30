/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:44:43 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/27 07:06:13 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	devide_a_to_b(t_info *info, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (info->pv2 <= info->a_stack->value)
		{
			ra(info, 0);
			info->ra++;
		}
		else
		{
			if (info->pv1 >= info->a_stack->value)
				pb(info);
			else
			{
				pb(info);
				rb(info, 0);
				info->rb++;
			}
			info->pb++;
		}
		i++;
	}
}

void	raise_a_b_part(t_info *info)
{
	int	ra;
	int	rb;

	ra = info->ra;
	rb = info->rb;
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

void	first_devide_a_to_b(t_info	*info, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (info->pv2 <= info->a_stack->value)
		{
			ra(info, 0);
			info->ra++;
		}
		else
		{
			if (info->pv1 <= info->a_stack->value)
				pb(info);
			else
			{
				pb(info);
				rb(info, 0);
				info->rb++;
			}
			info->pb++;
		}
		i++;
	}
}

void	first_a_to_b(t_info *info, int size)
{
	int	ra;
	int	pb;
	int	rb;

	if (size <= 3)
	{
		hard_sort_for_a(info, size);
		return ;
	}
	info->pv1 = info->num[info->arg_cnt / 3];
	info->pv2 = info->num[info->arg_cnt * 2 / 3];
	free(info->num);
	info->ra = 0;
	info->pb = 0;
	info->rb = 0;
	first_devide_a_to_b(info, size);
	ra = info->ra;
	pb = info->pb;
	rb = info->rb;
	a_to_b(info, ra);
	b_to_a(info, pb - rb);
	b_to_a(info, rb);
}

void	a_to_b(t_info	*info, int size)
{
	int	ra;
	int	pb;
	int	rb;
	int	*array;

	if (size <= 3)
		return (hard_sort_for_a(info, size));
	array = set_int_arr_for_sort(info->a_stack, size);
	bubblesort(array, size);
	info->pv1 = array[size / 3];
	info->pv2 = array[size * 2 / 3];
	free(array);
	info->ra = 0;
	info->pb = 0;
	info->rb = 0;
	devide_a_to_b(info, size);
	ra = info->ra;
	pb = info->pb;
	rb = info->rb;
	raise_a_b_part(info);
	a_to_b(info, ra);
	b_to_a(info, rb);
	b_to_a(info, pb - rb);
}
