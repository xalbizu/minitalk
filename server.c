/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:27:25 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/07/28 17:06:25 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

//static void	handler(int signum, siginfo_t *info, void *context);

int	main(void)
{
	// int					pid;
	// struct sigaction	sa;
	// sigset_t			blockmask;

	// pid = getpid();
	// ft_putnbr_fd(pid, 1);
	// sigemptyset(&blockmask);
	// sigaddset(&blockmask, SIGINT);
	// sigaddset(&blockmask, SIGQUIT);
	// sa.sa_handler = 0;
	// sa.sa_sigaction = handler;
	// sa.sa_flags = SA_SIGINFO;
	// sa.sa_mask = blockmask;
	// if (sigaction(SIGUSR1, &sa, NULL) == -1)
	// 	printf("error\n");
	// if (sigaction(SIGUSR2, &sa, NULL) == -1)
	// 	printf("error\n");
	// while (1)
	// 	pause();
	// return (0);
}

//static void	handler(int signum, siginfo_t *info, void *context)
//{
//	context ++;
//	printf("funciono %d, %d\n", signum);
//}
