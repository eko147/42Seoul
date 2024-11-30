/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:27:13 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/27 06:59:15 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info, int flag)
{
	t_list	*first;

	if (info->a_stack == NULL || info->a_stack->next == NULL)
		return ;
	first = info->a_stack;
	info->a_stack = info->a_stack->next;
	ft_lstlast(info->a_stack)->next = first;
	first->next = NULL;
	if (flag)
		return ;
	creat_oper_list(info, RA);
}

void	rb(t_info *info, int flag)
{
	t_list	*first;

	if (info->b_stack == NULL || info->b_stack->next == NULL)
		return ;
	first = info->b_stack;
	info->b_stack = info->b_stack->next;
	ft_lstlast(info->b_stack)->next = first;
	first->next = NULL;
	if (flag)
		return ;
	creat_oper_list(info, RB);
}

void	rr(t_info	*info)
{
	int	flag;

	flag = 1;
	ra(info, flag);
	rb(info, flag);
	creat_oper_list(info, RR);
	return ;
}
