/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taydogan <taydogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:44:49 by taydogan          #+#    #+#             */
/*   Updated: 2023/01/23 20:26:10 by taydogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	number;

	number = 0;
	while (*str)
		number = (10 * number) + (*str++ - 48);
	return (number);
}

void	ft_messages(int pid, char *message)
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

int main(int argc,char *argv[])
{
	int pid;
	char *messages;
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		messages = argv[2];
		ft_messages(pid, messages);
	}
	else
		write(1, "ERROR!\n", 7);
		
	return(0);
}
