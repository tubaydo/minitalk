/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:28:27 by binanc            #+#    #+#             */
/*   Updated: 2023/01/22 17:12:18 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	message_bits(int pid, char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		i = 8;
		c = *message++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		message = argv[2];
		pid = ft_atoi(argv[1]);
		message_bits(pid, message);
	}
	else
	{
		write(1, "ERROR\n", 6);
	}
	return (0);
}
