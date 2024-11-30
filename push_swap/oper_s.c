/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:47:03 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/26 20:46:07 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info	*info, int flag)
{
	int	tmp;

	if (info->a_stack == NULL || info->a_stack->next == NULL)
		return ;
	tmp = info->a_stack->value;
	info->a_stack->value = info->a_stack->next->value;
	info->a_stack->next->value = tmp;
	if (flag)
		return ;
	creat_oper_list(info, SA);
}

void	sb(t_info	*info, int flag)
{
	int	tmp;

	if (info->b_stack == NULL || info->b_stack->next == NULL)
		return ;
	tmp = info->b_stack->value;
	info->b_stack->value = info->b_stack->next->value;
	info->b_stack->next->value = tmp;
	if (flag)
		return ;
	creat_oper_list(info, SB);
}

void	ss(t_info	*info)
{
	int	flag;

	flag = 1;
	sa(info, flag);
	sb(info, flag);
	creat_oper_list(info, SS);
	return ;
}
