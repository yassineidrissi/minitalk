/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:06:07 by yaidriss          #+#    #+#             */
/*   Updated: 2023/02/03 23:45:16 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int				id;
	int				i;
	int				j;
	unsigned char	c;

	(void)ac;
	i = 0;
	j = -1;
	id = ft_atoi(av[1]);
	if (ac != 3 || !av[2] || !av[1] || id == -1)
		return (ft_printf("usage: ./client [valid server pid] [message]"));
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
	return (0);
}
