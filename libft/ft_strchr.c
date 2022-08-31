/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:06:09 by yidrissi          #+#    #+#             */
/*   Updated: 2021/12/01 19:15:25 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int		i;
	char	*s1;
	int		n;

	i = 0;
	s1 = (char *)s;
	n = ft_strlen(s1);
	while (i <= n)
	{
		if (s1[i] == (char)c)
		{
			return (&s1[i]);
		}
		i++;
	}
	return (0);
}
//ptr = &s1[i];