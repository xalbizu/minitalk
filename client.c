/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 14:50:32 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/07/28 17:05:23 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

int	main(int argc, char const *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		kill(pid, SIGUSR2);
	}
	else
	{
		printf("Error: Incorrect number of arguments recibed");
		printf(", required 2 (pid, string to send to server)\n");
	}
	return (0);
}
