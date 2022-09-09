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

// #include "minitalk.h"
#include <stdio.h>
#include <unistd.h>

int main (int ac, char **av)
{
  int i;
  i = getpid();
  printf("the pid is %d\n", i);
  while(1)
  {
    sleep(3);
    printf("we still running\n");
  }
}