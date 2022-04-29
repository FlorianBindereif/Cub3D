/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:49:58 by eozben            #+#    #+#             */
/*   Updated: 2021/06/25 18:57:17 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*end;

	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		if (lst->next == NULL)
			end = lst;
		lst = lst->next;
	}
	return (end);
}
