/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:47:01 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/01 17:27:37 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static unsigned char	c;
	static int				count;

	if (sig == SIGUSR1)
	{
		c = (c << 1) + 1;
		count++;
	}
	else if (sig == SIGUSR2)
	{
		c = c << 1;
		count++;
	}
	if (count == 8)
	{
		write(1,&c,1);
		count = 0;
		c = 0;
	}
}

int main (int ac, char **av)
{
	int i;
	(void)ac;
	(void)av;
	i = getpid();
	printf("the pid is %d\n", i);
	while(1)
	{
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler);
	pause();
	}
}