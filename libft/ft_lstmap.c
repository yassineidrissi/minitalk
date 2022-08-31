/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 21:31:04 by yidrissi          #+#    #+#             */
/*   Updated: 2022/08/14 17:02:11 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if(!lst || !del)
		return NULL;
	t_list *result;
	result	= (t_list *)malloc(sizeof(t_list)*ft_lstsize(lst));
	if(!result)
		return NULL;
	while(lst)
	{
		if(!lst->content)
		{
			result->content = f(lst->content);
			lst = lst->next;
			result = result->next;			
		}
		else
		{
				del(lst->content);
				result->content = f(lst->content);
				lst = lst->next;
				result = result->next;
		}
	}
	return result;
}

// if (!lst || !del)
// 		return (NULL);
// {
// 	t_list	*result;

// 	result = (t_list *)malloc(ft_lstsize(lst) * sizeof(t_list));
// 	if (!result)
// 		return (NULL);
// 	while (lst)
// 	{
// 		if (!(lst->content))
// 		{
// 			result = f(lst->content);
// 			lst = lst->next;
// 			result = result->next;
// 		}
// 		else
// 		{
// 			del(lst->content);
// 			result = f(lst->content);
// 			lst = lst->next;
// 			result = result->next;
// 		}
// 	}
// 	return (result);
// }
