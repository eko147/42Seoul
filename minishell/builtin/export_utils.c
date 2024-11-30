/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 20:08:22 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 15:05:08 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_name(char	*name)
{
	int	i;

	if (ft_isalpha(name[0]) == 0 && name[0] != '_')
		return (-1);
	i = 1;
	while (name[i] && name[i] != '=')
	{
		if (name[i] != '_' && ft_isdigit(name[i]) != 1 \
		&& ft_isalpha(name[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}

int	check_name_valid(char	*cmd)
{
	if (is_valid_name(cmd) == -1)
	{
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		return (1);
	}
	return (0);
}

int	len_env_list(t_env *head)
{
	int	len;

	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int	join_value(char	*str, int *i, char	**env_arr, t_env	**head)
{
	char	*tmp;

	tmp = str;
	if ((*head)->value == NULL)
	{
		env_arr[(*i)] = str;
		(*i)++;
		*head = (*head)->next;
		return (1);
	}
	str = ft_strjoin(str, "=\"");
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, (*head)->value);
	free(tmp);
	tmp = str;
	str = ft_strjoin(str, "\"");
	free(tmp);
	env_arr[(*i)] = str;
	return (0);
}

char	**env_list_to_array(t_env	*head)
{
	char	*str;
	char	**env;
	int		i;

	i = 0;
	env = ft_calloc(sizeof(char *) * (len_env_list(head) + 1), 1);
	while (head)
	{
		str = ft_strdup(head->name);
		if (join_value(str, &i, env, &head) == 1)
			continue ;
		i++;
		head = head->next;
	}
	return (env);
}
