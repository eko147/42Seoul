/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:49:15 by eunjiko           #+#    #+#             */
/*   Updated: 2023/01/15 21:23:45 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(int pid, int c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c /= 2;
		usleep(50);
	}
}

int	main(int argc, char	**argv)
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid > 99999)
		return (0);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		argv[2]++;
	}
	return (0);
}
