/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 02:28:52 by yidrissi          #+#    #+#             */
/*   Updated: 2023/02/01 19:24:09 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

static void	ft_init(int *i, long long int *s, unsigned long long int *n)
{
	*i = 0;
	*s = 1;
	*n = 0;
}

int	ft_atoi(const char *str)
{
	int							i;
	long long int				s;
	unsigned long long int		n;

	ft_init(&i, &s, &n);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			s = -s;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (n > 9223372036854775807)
	{
		if (s == 1)
			return (-1);
		return (0);
	}
	return ((int)(s * n));
}

// int	main(int	ac, char	**av)
// {
// 	printf("%d\n", ft_atoi(av[1]));
// 	printf("%d\n", atoi(av[1]));
// }