/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taydogan <taydogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:28:27 by tubaaydogan       #+#    #+#             */
/*   Updated: 2023/05/11 17:42:51 by taydogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	message_bits(int pid, char *message)
{
	int		i;
	char	c;

	while (*message)
	{
		i = 8;
		c = *message;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		message++;
	}
	i = 8;
}

int	ft_atoi(const char *str)
{
	int	number;

	number = 0;
	while (*str)
		number = (10 * number) + (*str++ - 48);
	return (number);
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
