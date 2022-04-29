/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 17:43:09 by eozben            #+#    #+#             */
/*   Updated: 2021/06/27 16:20:41 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*newelement;

	newelement = (t_list *)malloc(sizeof(t_list));
	if (!newelement)
		return (NULL);
	newelement->content = content;
	newelement->next = NULL;
	return (newelement);
}
