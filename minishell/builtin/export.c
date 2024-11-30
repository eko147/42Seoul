/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:13 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 16:24:31 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*find_env(t_env *env, char	*cmd, int name_len)
{
	char	*name;

	name = ft_calloc(name_len + 1, sizeof(char));
	ft_strlcpy(name, cmd, name_len + 1);
	while (env)
	{
		if (ft_strncmp(env->name, name, env->name_len + 1) == 0)
		{
			free(name);
			return (env);
		}
		env = env->next;
	}
	free(name);
	return (NULL);
}

void	sort_env(char	**env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (env == NULL || env[0] == NULL || env[1] == NULL)
		return ;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strncmp(env[i], env[j], ft_strlen(env[i]) + 1) > 0)
			{
				tmp = env[i];
				env[i] = env[j];
				env[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	create_new(char	*cmd, int name_len, t_env_deque	*envs)
{
	t_env	*new;

	new = lstnew_env();
	new->name = ft_calloc(name_len + 1, sizeof(char));
	new->name_len = name_len;
	ft_strlcpy(new->name, cmd, name_len + 1);
	if (*(cmd + name_len) != '\0')
		new->value = ft_strdup(cmd + name_len + 1);
	if (*(cmd + name_len) != '\0')
		new->value_len = ft_strlen(cmd + name_len + 1);
	else
		new->value_len = 0;
	append_tail_env(&envs->head, &envs->tail, new);
}

void	create_or_update_env(t_env_deque	*envs, char	**cmd, int	*flag)
{
	int		i;
	int		name_len;
	t_env	*env_ptr;

	i = 0;
	while (cmd[++i] != NULL)
	{
		*flag = check_name_valid(cmd[i]);
		if (ft_strchr(cmd[i], '='))
			name_len = ft_strchr(cmd[i], '=') - cmd[i];
		else
			name_len = ft_strlen(cmd[i]);
		env_ptr = find_env(envs->head, cmd[i], name_len);
		if (env_ptr)
		{
			if (*(cmd[i] + name_len) != '\0')
			{	
				free(env_ptr->value);
				env_ptr->value = ft_strdup(cmd[i] + name_len + 1);
				env_ptr->value_len = ft_strlen(cmd[i] + name_len + 1);
			}
		}
		else
			create_new(cmd[i], name_len, envs);
	}
}

int	ft_export(t_env_deque	*envs, char	**cmd)
{
	char	**env;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (cmd[1] == NULL)
	{
		env = env_list_to_array(envs->head);
		sort_env(env);
		while (env[i])
			printf("declare -x %s\n", env[i++]);
		free_arrs(env);
	}
	else
		create_or_update_env(envs, cmd, &flag);
	return (flag);
}
