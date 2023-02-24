/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taydogan <taydogan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:44:58 by taydogan          #+#    #+#             */
/*   Updated: 2023/01/23 20:42:51 by taydogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>

void	ft_itoa(int pid)
{
	char	c;

	if (pid >= 10)
		ft_itoa(pid / 10);
	c = (pid % 10) + 48;
	write(1, &c, 1);
}

void read_bit(int binarymessage)
{
    static int	i = 7;
	static int	character = 0;

	character += binarymessage << i;
	if (i == 0)
	{
		i = 7;
		write(1, &character, 1);
		character = 0;
	}
	else
		i--;
}

void my_handler(int sig)
{
	if(sig == SIGUSR1)
		read_bit(0);
	else if(sig == SIGUSR2)
		read_bit(1);
	
}

int main()
{
    write(1, "Server Pid : ", 13);
    ft_itoa(getpid());
    write(1, "\n", 1);
	signal(SIGUSR2,my_handler);
	signal(SIGUSR1,my_handler);
	pause();
    return 0;
}
