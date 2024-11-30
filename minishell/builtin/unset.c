/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:29:18 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 15:05:40 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env(void *env)
{
	t_env	*temp;

	temp = (t_env *)env;
	free(temp->name);
	if (temp->value)
		free(temp->value);
	free(temp);
}

int	len_double_arr(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

void	remove_env(t_env_deque *envs, t_env *env)
{
	if (env->previous == NULL)
		envs->head = env->next;
	else
		env->previous->next = env->next;
	if (env->next == NULL)
		envs->tail = env->previous;
	else
		env->next->previous = env->previous;
	free_env(env);
}

int	remove_envs(int cmd_len, t_env_deque *envs, char **cmd, t_env *env)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (++i < cmd_len)
	{
		if (is_valid_name(cmd[i]) == -1)
		{
			print_builtin_error("unset", cmd[i]);
			flag = 1;
			continue ;
		}
		env = envs ->head;
		while (env != NULL)
		{
			if (ft_strncmp(cmd[i], env->name, ft_strlen(env->name) + 1) == 0)
			{
				remove_env(envs, env);
				break ;
			}
			env = env->next;
		}
	}
	return (flag);
}

int	ft_unset(t_env_deque *envs, char **cmd)
{
	int		cmd_len;
	int		flag;

	flag = 0;
	cmd_len = len_double_arr(cmd);
	if (cmd_len < 2)
		return (flag);
	flag = remove_envs(cmd_len, envs, cmd, envs->head);
	return (flag);
}
