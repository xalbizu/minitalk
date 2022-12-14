/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:50:32 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/07/30 15:28:28 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str_to_binary(argv[2], pid);
	}
	else
	{
		printf("Error: Incorrect number of arguments recibed");
		printf(", required 2 (pid, string to send to server)\n");
	}
}

void	str_to_binary(char *str, int pid)
{
	int		i;
	int		j;
	char	byte[8];

	i = 0;
	while (str[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] % 2 == 1)
			byte[j] = '1';
			else
				byte[j] = '0';
			str[i] = str[i] / 2;
			j--;
		}
		i++;
		send_binary(byte, pid);
	}
}

void	send_binary(char *byte, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (byte[i] == '0')
			kill(pid, SIGUSR1);
		else if (byte[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(42);
	}
}
