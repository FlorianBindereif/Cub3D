/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:56:04 by eozben            #+#    #+#             */
/*   Updated: 2022/01/13 14:58:22 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putbase_nbr(long num, unsigned int base, char *digits)
{
	if (num < base)
		ft_putchar_fd(digits[num], 1);
	else
	{
		ft_putbase_nbr(num / base, base, digits);
		ft_putchar_fd(digits[num % base], 1);
	}
}

void	ft_putbase(long num, unsigned int base, char *digits)
{
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putbase_nbr(-num, base, digits);
	}
	else
		ft_putbase_nbr(num, base, digits);
}
