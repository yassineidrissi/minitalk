/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:06:07 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/01 21:05:19 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int						id;
	unsigned char	c;

	(void)ac;
  int i = 0;
  int j = -1;
  if (ac != 3)
  {
    ft_printf("usage: ./client [server pid] [message]");
    return 0;
  }
  id = ft_atoi(av[1]);
  if (id == -1) 
  {
    ft_printf("usage: ./client [valid server pid] [message]");
    return 0;
  }

  //!zid atoi  
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
  return (0);
}