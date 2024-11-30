/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 02:44:22 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/04 21:37:24 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	part_of_hard_sort_for_a(t_info *info, int fst, int sec, int thd)
{
	if (fst < sec && sec > thd && fst > thd)
	{
		ra(info, 0);
		sa(info, 0);
		rra(info, 0);
		sa(info, 0);
	}
	if (fst > sec && sec < thd && fst > thd)
	{
		sa(info, 0);
		ra(info, 0);
		sa(info, 0);
		rra(info, 0);
	}
	if (fst > sec && sec > thd && fst > thd)
	{
		sa(info, 0);
		ra(info, 0);
		sa(info, 0);
		rra(info, 0);
		sa(info, 0);
	}
}

void	hard_sort_for_a(t_info *info, int size)
{
	int	fst;
	int	sec;
	int	thd;

	if (size == 2)
	{
		if (info->a_stack->value > info->a_stack->next->value)
			sa(info, 0);
	}
	else if (size == 3)
	{
		fst = info->a_stack->value;
		sec = info->a_stack->next->value;
		thd = info->a_stack->next->next->value;
		if (fst < sec && sec > thd && fst < thd)
		{
			ra(info, 0);
			sa(info, 0);
			rra(info, 0);
		}
		if (fst > sec && sec < thd && fst < thd)
			sa(info, 0);
		part_of_hard_sort_for_a(info, fst, sec, thd);
	}
	return ;
}

void	part_of_hard_sort_for_b(t_info *info, int fst, int sec, int thd)
{
	if (fst < sec && sec < thd && fst < thd)
	{
		rb(info, 0);
		sb(info, 0);
		pa(info);
		pa(info);
		rrb(info, 0);
		pa(info);
	}
	if (fst < sec && sec > thd && fst < thd)
	{
		rb(info, 0);
		pa(info);
		pa(info);
		rrb(info, 0);
		pa(info);
	}
	if (fst > sec && sec < thd && fst < thd)
	{
		pa(info);
		sb(info, 0);
		pa(info);
		sa(info, 0);
		pa(info);
	}
}

void	part2_of_hard_sort_for_b(t_info *info, int fst, int sec, int thd)
{
	if (fst < sec && sec > thd && fst > thd)
	{
		pa(info);
		pa(info);
		sa(info, 0);
		pa(info);
	}
	if (fst > sec && sec < thd && fst > thd)
	{
		pa(info);
		pa(info);
		pa(info);
		sa(info, 0);
	}
	if (fst > sec && sec > thd && fst > thd)
	{
		pa(info);
		pa(info);
		pa(info);
	}
}

void	hard_sort_for_b(t_info *info, int size)
{
	int	fst;
	int	sec;
	int	thd;

	if (size == 1)
		pa(info);
	else if (size == 2)
	{
		if (info->b_stack->value < info->b_stack->next->value)
			sb(info, 0);
		pa(info);
		pa(info);
	}
	else if (size == 3)
	{
		fst = info->b_stack->value;
		sec = info->b_stack->next->value;
		thd = info->b_stack->next->next->value;
		part_of_hard_sort_for_b(info, fst, sec, thd);
		part2_of_hard_sort_for_b(info, fst, sec, thd);
	}
	return ;
}
