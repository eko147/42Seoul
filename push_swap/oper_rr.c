/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:24:43 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/27 06:58:02 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info	*info, int flag)
{
	t_list	*first;
	int		i;

	if (info->a_stack == NULL || info->a_stack->next == NULL)
		return ;
	first = info->a_stack;
	i = second_to_last(first);
	info->a_stack = ft_lstlast(info->a_stack);
	info->a_stack->next = first;
	while (i--)
		first = first->next;
	first->next = NULL;
	if (flag)
		return ;
	creat_oper_list(info, RRA);
}

void	rrb(t_info	*info, int flag)
{
	t_list	*first;
	int		i;

	if (info->b_stack == NULL || info->b_stack->next == NULL)
		return ;
	first = info->b_stack;
	i = second_to_last(first);
	info->b_stack = ft_lstlast(info->b_stack);
	info->b_stack->next = first;
	while (i--)
		first = first->next;
	first->next = NULL;
	if (flag)
		return ;
	creat_oper_list(info, RRB);
}

void	rrr(t_info *info)
{
	int	flag;

	flag = 1;
	rra(info, flag);
	rrb(info, flag);
	creat_oper_list(info, RRR);
	return ;
}
