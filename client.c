/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:46:32 by yaidriss          #+#    #+#             */
/*   Updated: 2022/09/03 10:32:28by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac,char **av)
{
	(void)ac;
  int id;
  int i = 0;
  int j = -1;
  unsigned char c;
  if (ac != 3)
  {
    printf("usage: ./client [server pid] [message]");
    return 0;
  }
  id = atoi(av[1]); //!zid atoi  
  while(av[2][++j])
  {
    i = 8;
    c = av[2][j];
    while(--i > -1)
    {
      if((c >> i) & 1)
        kill(id,SIGUSR1);
      else
        kill(id,SIGUSR2);
      usleep(100);
    }
  }
}