/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 05:35:49 by yidrissi          #+#    #+#             */
/*   Updated: 2022/08/13 14:18:56 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;
	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

// int main()
// {
// 	char *content = "yassine";
// 	t_list yas;
// 	yas.next =ft_lstnew(content);
// 	printf("the content is now is %s", yas.next->content);
// 	return 0;
// }