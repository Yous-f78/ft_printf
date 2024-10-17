/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeskine <ymeskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:13:36 by ymeskine          #+#    #+#             */
/*   Updated: 2024/10/01 11:13:37 by ymeskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(long int nb, char format)
{
	int			len;
	char		c;

	len = 0;
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 16)
	{
		len += ft_puthexa(nb / 16, format);
		len += ft_puthexa(nb % 16, format);
	}
	else
	{
		if (nb < 10)
			c = nb + 48;
		else
			c = nb - 10 + format - 23;
		len += write(1, &c, 1);
	}
	return (len);
}
