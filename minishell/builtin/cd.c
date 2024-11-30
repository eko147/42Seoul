/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:09:09 by eunjiko           #+#    #+#             */
/*   Updated: 2023/03/28 16:48:12 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	old_pwd(t_env *head, char *path, t_env_deque *envs)
{
	t_env	*oldpwd_env;
	char	*str;

	oldpwd_env = find_env(head, "OLDPWD", 6);
	if (oldpwd_env)
	{
		oldpwd_env->value_len = 0;
		free (oldpwd_env->value);
		oldpwd_env->value = path;
		oldpwd_env->value_len = ft_strlen(path);
		return ;
	}
	else
	{
		str = ft_strjoin("OLDPWD=", path);
		create_new(str, 6, envs);
		free(str);
		free(path);
	}
}

void	cat_valid_path(t_env_deque *envs, char *cwd, char *path, int *flag)
{
	t_env	*pwd_env;
	char	*str;

	print_builtin_error("cd", path);
	pwd_env = find_env(envs->head, "PWD", 3);
	if (pwd_env)
	{
		if (pwd_env->value == NULL)
			pwd_env->value = ft_strdup("");
		old_pwd(envs->head, pwd_env->value, envs);
		str = ft_strjoin(pwd_env->value, "/");
		pwd_env->value = ft_strjoin(str, path);
		free(str);
	}
	free(cwd);
	*flag = 1;
}

void	update_pwd(t_env *head, t_env_deque *envs, char *path, int	*flag)
{
	char	*cwd;
	t_env	*pwd_env;
	char	*str;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (cat_valid_path(envs, cwd, path, flag));
	pwd_env = find_env(head, "PWD", 3);
	if (pwd_env)
	{
		if (pwd_env->value == NULL)
			pwd_env->value = ft_strdup("");
		old_pwd(head, pwd_env->value, envs);
		pwd_env->value = ft_strdup(cwd);
	}
	else
	{
		old_pwd(head, ft_strdup(""), envs);
		str = ft_strjoin("PWD=", cwd);
		create_new(str, 3, envs);
		free(str);
	}
	free(cwd);
	return ;
}

void	cd_home(t_env *head, t_env_deque *envs, int *flag, char *path)
{
	char	*home_dir;

	home_dir = ft_getenv(head, "HOME");
	if (home_dir == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		*flag = 1;
	}
	else
	{
		if (chdir(home_dir) == -1)
		{
			print_builtin_error("cd", home_dir);
			*flag = 1;
			return ;
		}
		update_pwd(head, envs, path, flag);
	}
	return ;
}

int	ft_cd(char **cmd, t_env *head, t_env_deque	*envs)
{
	int		flag;

	flag = 0;
	if (cmd[1] == NULL)
	{
		cd_home(head, envs, &flag, cmd[1]);
		return (flag);
	}
	if (chdir(cmd[1]) == -1)
	{
		if (access(cmd[1], F_OK) == -1)
			print_error(OPEN_ERROR, "cd");
		else if (access(cmd[1], X_OK) == -1)
			print_error(PERMISSION_ERROR, "cd");
		else
			print_builtin_error("cd", cmd[1]);
		return (1);
	}
	update_pwd(head, envs, cmd[1], &flag);
	return (flag);
}
