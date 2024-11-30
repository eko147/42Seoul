/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:45:57 by eunjiko          #+#    #+#             */
/*   Updated: 2023/03/27 15:36:52 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(char **cmd)
{
	int	tmp;

	if (cmd[1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	else if (cmd[1] != NULL)
	{
		printf("exit\n");
		tmp = ft_atoi(cmd[1]);
		if (check_numeric(cmd[1]) != 0 || \
		(cmd[1][0] != '-' && tmp == -1) || (cmd[1][0] == '-' && tmp == 0))
		{
			print_builtin_error("exit", cmd[1]);
			exit (255);
		}
		else if (cmd[2] != NULL)
		{
			ft_putendl_fd("minishell: exit: too many arguments", 2);
			return ;
		}
		exit(tmp);
	}
}
