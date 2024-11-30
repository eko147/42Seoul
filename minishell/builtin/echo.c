/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:05:49 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 16:24:46 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_echo(char **argv, int i)
{
	if (argv[i] == NULL)
		printf("");
	else
		printf("%s", argv[i]);
	if (argv[i] && argv[i + 1] != NULL)
		printf(" ");
}

int	check_echo_flag(char *str)
{
	int	i;

	if (str != NULL)
	{
		if (str[0] == '-')
		{
			i = 1;
			while (str[i] != '\0')
			{
				if (str[i] != 'n')
					return (0);
				i++;
			}
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int	ft_echo(char **argv)
{
	int	i;
	int	n_flag;
	int	cnt;

	i = 1;
	cnt = 0;
	n_flag = (check_echo_flag(argv[1]));
	while (argv[i] != NULL)
	{
		if (n_flag == 1)
		{
			i++;
			cnt++;
			while (argv[i] != NULL && check_echo_flag(argv[i]) != 0)
				i++;
			n_flag = 0;
		}
		print_echo(argv, i);
		if (argv[i] == NULL)
			break ;
		i++;
	}
	if (cnt == 0)
		printf("\n");
	return (0);
}
