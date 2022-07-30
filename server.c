/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:27:25 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/07/30 15:28:24 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

static void	handler(int signum, siginfo_t *info, void *context);

int	main(void)
{
	int					pid;
	struct sigaction	sa;
	sigset_t			blockmask;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	sigemptyset(&blockmask);
	sigaddset(&blockmask, SIGINT);
	sigaddset(&blockmask, SIGQUIT);
	sa.sa_handler = 0;
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = blockmask;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		write(1, "error\n", 7);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		write(1, "error\n", 7);
	while (1)
		pause();
	return (0);
}

static void	handler(int signum, siginfo_t *info, void *context)
{
	static char	byte[9] = {'2', '2', '2', '2', '2', '2', '2', '2', '\0'};

	context++;
	info->si_pid = 0;
	if (signum == SIGUSR1)
		set_byte(byte, '0');
	else if (signum == SIGUSR2)
		set_byte(byte, '1');
}

void	set_byte(char *byte, char bit)
{
	int	i;

	i = 0;
	while (i < 7 && byte[i] != '2')
		i++;
	byte[i] = bit;
	if (i == 7)
	{
		byte_to_char(byte);
		while (i-- >= 0)
			byte[i + 1] = '2';
	}
}

void	byte_to_char(char *byte)
{
	char	c;
	int		sum;
	int		i;

	i = 7;
	sum = 1;
	c = 0;
	while (i >= 0)
	{
		if (byte[i] == '1')
			c += sum;
		sum = sum * 2;
		i--;
	}
	write(1, &c, 1);
}
