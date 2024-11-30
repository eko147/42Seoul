/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:09:23 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 16:16:49 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(t_env *head, char *name)
{
	while (head)
	{
		if (ft_strncmp(head->name, name, ft_strlen(name) + 1) == 0)
			return (head->value);
		head = head->next;
	}
	return (NULL);
}

void	free_arrs(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_env	*find_target(char *str, t_env_deque *envs)
{
	t_env	*target;

	target = envs->head;
	while (target != NULL)
	{
		if (ft_strncmp(str, target->name, ft_strlen(str) + 1) == 0)
			return (target);
		target = target->next;
	}
	return (0);
}

void	print_builtin_error(char *arg, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	if (arg != NULL)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	if (ft_strcmp(arg, "cd") == 0)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": Not a directory", 2);
	}
	if (ft_strcmp(arg, "unset") == 0)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": not a valid identifier", 2);
	}
	else if (ft_strcmp(arg, "exit") == 0)
	{
		ft_putstr_fd(str, 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
}
