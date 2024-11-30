/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:36:13 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/04 21:36:22 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_from_err(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

void	str_to_int_array(t_info *info, int ac, char **av)
{
	int		i;
	char	**splited;
	char	*line;
	char	*tmp;

	i = 1;
	info->arg_cnt = 0;
	line = ft_strdup("");
	while (i < ac)
	{
		tmp = line;
		line = ft_strjoin(line, av[i++]);
		free(tmp);
	}
	splited = ft_split(line, ' ', &info->arg_cnt);
	free(line);
	info->num = malloc(sizeof(int) * info->arg_cnt);
	i = 0;
	while (splited[i])
	{
		info->num[i] = ft_atoi(splited[i], 0, 1, 0);
		i++;
	}
	free_all(splited);
}

void	creat_a_stack(t_info *info)
{
	int		i;
	t_list	*tmp;
	t_list	*prev;

	i = 0;
	while (i < info->arg_cnt)
	{
		tmp = malloc(sizeof(t_list));
		if (i == 0)
			info->a_stack = tmp;
		else
			prev->next = tmp;
		tmp->value = info->num[i];
		tmp->next = NULL;
		prev = tmp;
		i++;
	}
}

void	creat_oper_list(t_info *info, t_oper type)
{
	t_list	*tmp;
	t_list	*last;

	if (info->oper_list == NULL)
	{
		info->oper_list = malloc(sizeof(t_list));
		info->oper_list->value = type;
		info->oper_list->next = NULL;
	}
	else
	{
		last = ft_lstlast(info->oper_list);
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			exit_from_err("MALLOC ERROR");
		last->next = tmp;
		tmp->value = type;
		tmp->next = NULL;
	}
}

int	main(int ac, char **av)
{
	t_info	info;

	info.b_stack = NULL;
	info.oper_list = NULL;
	if (ac == 1)
		exit_from_err("argument is empty");
	str_to_int_array(&info, ac, av);
	check_sort(&info);
	creat_a_stack(&info);
	check_double(&info);
	if (info.arg_cnt == 3)
	{
		hard_sort(&info);
		return (0);
	}
	first_a_to_b(&info, info.arg_cnt);
	print_oper_list(info.oper_list);
	return (0);
}
