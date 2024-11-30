/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:38:27 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/04 19:18:36 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_str(char	*str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	oper_list(t_oper type)
{
	if (type == SA)
		print_str("sa");
	if (type == SB)
		print_str("sb");
	if (type == SS)
		print_str("ss");
	if (type == PA)
		print_str("pa");
	if (type == PB)
		print_str("pb");
	if (type == RA)
		print_str("ra");
	if (type == RB)
		print_str("rb");
	if (type == RR)
		print_str("rr");
	if (type == RRA)
		print_str("rra");
	if (type == RRB)
		print_str("rrb");
	if (type == RRR)
		print_str("rrr");
}

t_list	*part_of_print_oper_list(t_list *oper)
{
	if ((oper->value == SA && oper->next->value == SB) \
	|| (oper->value == SB && oper->next->value == SA))
	{
		print_str("ss");
		oper = oper->next;
	}
	else if ((oper->value == RA && oper->next->value == RB) \
	|| (oper->value == RB && oper->next->value == RA))
	{
		print_str("rr");
		oper = oper->next;
	}
	else if ((oper->value == RRA && oper->next->value == RRB) \
	|| (oper->value == RRB && oper->next->value == RRA))
	{
		print_str("rrr");
		oper = oper->next;
	}		
	else
		oper_list(oper->value);
	oper = oper->next;
	return (oper);
}

void	print_oper_list(t_list	*oper)
{
	if (oper == NULL)
		return ;
	while (oper->next)
	{
		oper = part_of_print_oper_list(oper);
		if (oper == NULL)
			break ;
	}
	if (oper)
		oper_list(oper->value);
}
