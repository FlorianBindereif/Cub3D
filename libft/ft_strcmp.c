/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:56:15 by eozben            #+#    #+#             */
/*   Updated: 2021/12/11 14:13:02 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (1)
	{
		if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
			return (1);
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (0);
		i++;
	}
}