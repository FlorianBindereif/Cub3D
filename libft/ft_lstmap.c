/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:38:35 by eozben            #+#    #+#             */
/*   Updated: 2021/06/28 16:25:47 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*start;
	t_list	*element;
	int		len;

	len = ft_lstsize(lst);
	start = lst;
	newlst = (t_list *)malloc(sizeof(t_list) * len);
	if (!newlst)
		return ((t_list *) NULL);
	newlst = NULL;
	while (lst != NULL)
	{
		element = ft_lstnew((t_list *)f((t_list *)lst->content));
		if (!element)
			ft_lstclear(&start, del);
		else
			ft_lstadd_front(&newlst, element);
		lst = lst->next;
	}
	return (newlst);
}
