/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeskine <ymeskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:14:08 by ymeskine          #+#    #+#             */
/*   Updated: 2024/10/01 11:14:11 by ymeskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	long unsigned int	nb;
	int					len;
	char				c;

	nb = n;
	len = 0;
	if (nb >= 10)
		len += ft_putunsigned(nb / 10);
	c = nb % 10 + 48;
	len += write(1, &c, 1);
	return (len);
}
