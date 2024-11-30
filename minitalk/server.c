/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:02:40 by eunjiko           #+#    #+#             */
/*   Updated: 2023/01/15 21:23:44 by eunjiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_sig(int signum)
{
	static char	temp;
	static int	bit;

	if (signum == SIGUSR1)
		temp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &temp, 1);
		bit = 0;
		temp = 0;
	}
}

int	main(void)
{
	write(1, "pid: ", 5);
	print_pid(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, print_sig);
	signal(SIGUSR2, print_sig);
	while (1)
		pause ();
	return (0);
}
