/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:59:43 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/04 16:10:22 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_end(int id)
{
	int	i;

	i = 8;
	while (--i > -1)
	{
		kill (id, SIGUSR2);
		usleep(100);
	}
}

void	ft_handle_conv(char **av, int id)
{
	int				i;
	int				j;
	unsigned char	c;

	i = 0;
	j = -1;
	while (av[2][++j])
	{
		i = 8;
		c = av[2][j];
		while (--i > -1)
		{
			if ((c >> i) & 1)
				kill (id, SIGUSR1);
			else
				kill (id, SIGUSR2);
			usleep(100);
		}
	}
	ft_send_end(id);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR2)
		ft_printf("Message recieved✅\n");
}

int	main(int ac, char **av)
{
	static int					id;
	struct sigaction			action;

	(void)ac;
	id = ft_atoi(av[1]);
	if (ac != 3 || !av[2] || !av[1] || id == -1)
		return (ft_printf("usage: ./client [valid server pid] [message]"));
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = handler;
	sigaction(SIGUSR2, &action, NULL);
	ft_handle_conv(av, id);
	return (0);
}
