/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:47:01 by yaidriss          #+#    #+#             */
/*   Updated: 2022/09/10 02:35:25 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int count = 0;
char c = 0;

void ft_add_sr1(int sugmen)
{
	printf("we recieved 1\n");
	count++;
	c = c << 1;
	if (count == 7)
	{
		printf("%c",c);
		count = 0;
	}
}

void ft_add_sr2(int sugmen)
{
	printf("we recieved 0\n");
	count++;
	c = c << 0;
	if (count == 7)
	{
		printf("%c",c);
		count = 0;
	}
}

int main (int ac, char **av)
{
  int i;
  i = getpid();
  printf("the pid is %d\n", i);
  while(1)
  {
	signal(SIGUSR1,ft_add_sr1);
	signal(SIGUSR2,ft_add_sr2);
  }
}