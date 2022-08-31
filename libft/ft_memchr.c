/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:27:26 by yidrissi          #+#    #+#             */
/*   Updated: 2021/11/29 21:44:04 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"
#include <stdlib.h>

void	*ft_memchr(const void *s1, int c, size_t n)
{
	unsigned char		*temp;
	size_t				i;

	i = 0;
	temp = (unsigned char *)s1;
	if (!n)
		return (0);
	while (i < n)
	{
		if (temp[i] == (unsigned char )c)
			return ((void *)&temp[i]);
		i++;
	}
	return (0);
}
