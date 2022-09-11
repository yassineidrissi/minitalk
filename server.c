/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:47:01 by yaidriss          #+#    #+#             */
/*   Updated: 2022/09/11 20:21:31 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int count = 0;
char c = 0;
void ft_print_biniry(int bin)
{
	  int i = 7;
  while(i >= 0)
  {
	if((bin >> i) & 1)
	  printf("1");
	else
	  printf("0");
	i--;
  }
  printf("\n");
}

void ft_add_sr1(int sugmen)
{
	(void)sugmen;
	// printf("we recieved 1\n");
	c = (c << 1) + 1;
	count++;
	// printf("the count now is %d\n",count);
	if (count == 8)
	{
		// printf("we recieved in biniry =====> ");
		// ft_print_biniry(c);
		// printf("*********we pirnt******* =====> %c\n",c);
		write(1,&c,1);
		count = 0;
		c = 0;
	}
	usleep(100);
}

void ft_add_sr2(int sugmen)
{
	(void)sugmen;
	// printf("the count now is %d\n",count);
	// printf("we recieved 0\n");
	c = c << 1;
	count++;
	if (count == 8)
	{
		// printf("we recieved in biniry =====> ");
		// ft_print_biniry(c);
		// printf("*********we pirnt******* =====>%c\n",c);
		write(1,&c,1);
		count = 0;
		c = 0;
	}
	usleep(100);
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
	signal(SIGUSR1,ft_add_sr1);
	signal(SIGUSR2,ft_add_sr2);
	pause();
	}
}