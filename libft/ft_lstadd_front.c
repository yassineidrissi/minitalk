/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 06:34:47 by yidrissi          #+#    #+#             */
/*   Updated: 2022/08/13 14:54:08 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list	**alst, t_list	*new)
{
	if (!alst)
		return ;
	new->next = *alst;
	*alst = new;
}

// void show_list(t_list *head)
// {
//     while (head)
//     {
//      printf("%s - %p \n",head->content,head);
//      head = head->next;
//     }
// }
// t_list *ft_lstnew(void *content)
// {
//     t_list	*result;
// 	result = (t_list *)malloc(sizeof(t_list));
// 	result->content = content;
// 	result->next = 0;
// 	return(result);
// }
// int main()
// {
// 	t_list	*n1;
//     t_list	*n2;
//     t_list	*n3;

//     n1 = ft_lstnew("a1");
//     n2 = ft_lstnew("a2");
//     n3 = ft_lstnew("a3");
//     ft_lstadd_front( &n3, n2);
//     ft_lstadd_front( &n2, n1);

//     show_list(n1);
// }