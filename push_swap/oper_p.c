/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:03:26 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/27 06:59:41 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_info	*info)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	if (info->a_stack == NULL)
		return ;
	tmp_a = info->a_stack;
	tmp_b = info->b_stack;
	info->a_stack = tmp_a->next;
	info->b_stack = tmp_a;
	tmp_a->next = tmp_b;
	creat_oper_list(info, PB);
}

void	pa(t_info	*info)
{
	t_list	*tmp_b;
	t_list	*tmp_a;

	if (info->b_stack == NULL)
		return ;
	tmp_b = info->b_stack;
	tmp_a = info->a_stack;
	info->b_stack = tmp_b->next;
	info->a_stack = tmp_b;
	tmp_b->next = tmp_a;
	creat_oper_list(info, PA);
}
