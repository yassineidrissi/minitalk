/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidrissi <yassine1337idrissi@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 09:51:04 by yidrissi          #+#    #+#             */
/*   Updated: 2021/12/01 19:14:40 by yidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void	*s2, size_t	n)
{
	size_t					i;
	unsigned char			*t_str1;
	unsigned char			*t_str2;

	i = 0;
	t_str1 = (unsigned char *)s1;
	t_str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (t_str1[i] == t_str2[i] && i < n - 1)
		i++;
	return (t_str1[i] - t_str2[i]);
}
