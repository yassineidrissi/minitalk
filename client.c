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
  int id;
  int i = 0;
  int j = -1;
  id = atoi(av[1]);
  // kill(id,SIGSTOP);
  while(av[2][++j])
  {
    i = -1;
    while(++i < 8)
    {
      if((av[2][j] >> i) & 1)
        kill(id,SIGUSR1);
      else
        kill(id,SIGUSR2);
    }
    usleep(100);
  }
}