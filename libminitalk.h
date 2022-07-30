/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xalbizu- <xalbizu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:26:35 by xalbizu-          #+#    #+#             */
/*   Updated: 2022/07/30 15:28:14 by xalbizu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINITALK_H
# define LIBMINITALK_H

# include <signal.h>
# include <unistd.h>
# include "libft/libft.h"

void	str_to_binary(char *str, int pid);
void	send_binary(char *byte, int pid);
void	set_byte(char *byte, char bit);
void	byte_to_char(char *byte);
#endif