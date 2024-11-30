/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:05:53 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 15:41:17 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_env	*head, char	**cmd)
{
	if (cmd[1] != NULL)
	{
		if (ft_strcmp(cmd[0], "env") == 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd("env: ", 2);
			ft_putstr_fd(cmd[1], 2);
			ft_putendl_fd(": No such file or directory", 2);
		}
		return (127);
	}
	while (head)
	{
		if (head->value != NULL)
			printf("%s=%s\n", head->name, head->value);
		head = head->next;
	}
	return (0);
}

int	ft_pwd(t_env_deque *envs)
{
	char	*pwd;
	char	*buf;
	t_env	*env;
	int		flag;

	flag = 0;
	buf = ft_calloc(4096, 1);
	pwd = getcwd(buf, 4096);
	if (pwd == NULL)
	{
		env = find_target("PWD", envs);
		if (env == NULL)
		{
			ft_putstr_fd("pwd: error retrieving current directory\n", 2);
			ft_putstr_fd("getcwd: cannot access parent directories\n", 2);
			ft_putendl_fd(": No such file or directory", 2);
			free(buf);
			return (1);
		}
		printf("%s\n", env->value);
	}
	else
		printf("%s\n", pwd);
	free(buf);
	return (flag);
}
