/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:47:01 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/01 19:43:58 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int				count;
	static int				pid;

	(void)ucontext;
	if (info->si_pid != pid)
	{
		pid = info->si_pid;
		count = 0;
		c = 0;
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			c = (c << 1) + 1;
		else
			c = c << 1;
		count++;
	}
	if (count == 8)
	{
		write(1, &c, 1);
		count = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int					i;
	struct sigaction	action;

	(void)av;
	if (ac != 1)
	{
		ft_printf("usage: ./server");
		return (0);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	i = getpid();
	ft_printf("the pid is %d\n", i);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
}
