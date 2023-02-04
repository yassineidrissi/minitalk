/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:08:29 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/04 16:11:11 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handl_errors(siginfo_t *info, int *i, unsigned char *c, int *pid)
{
	if (info->si_pid != *pid)
	{
		*pid = info->si_pid ;
		*i = 0;
		*c = 0;
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int					pid;
	static unsigned char		c = 0;
	static int					i = 0;

	(void)context;
	handl_errors(info, &i, &c, &pid);
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1)
			c = (c << 1) + 1;
		else
			c = c << 1;
		i++;
	}
	if (i == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR2);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;
	static int			pid = 0;

	(void)av;
	if (ac != 1)
	{
		ft_printf("usage: ./server");
		return (0);
	}
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	pid = getpid();
	ft_printf("the pid is %d\n", pid);
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
