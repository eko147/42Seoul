/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:47:06 by eunjiko           #+#    #+#             */
/*   Updated: 2023/02/27 04:13:43 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double(t_info	*info)
{
	int	i;

	i = 0;
	bubblesort(info->num, info->arg_cnt);
	while (i < info->arg_cnt - 1)
	{
		if (info->num[i] == info->num[i + 1])
			exit_from_err("same number");
		i++;
	}
}

void	check_sort(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->arg_cnt - 1)
	{
		if (info->num[i] >= info->num[i + 1])
			return ;
		i++;
	}
	exit(0);
}

void	bubblesort(int arr[], int n)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

int	second_to_last(t_list *lst)
{
	int	i;

	i = 0;
	while (lst -> next)
	{
		lst = lst -> next;
		i++;
	}
	return (i - 1);
}
