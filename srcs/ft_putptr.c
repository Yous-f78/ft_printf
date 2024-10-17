/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymeskine <ymeskine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:13:51 by ymeskine          #+#    #+#             */
/*   Updated: 2024/10/01 11:13:54 by ymeskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_adress(size_t nb)
{
	char		c;
	int			len_sizet;

	len_sizet = 0;
	if (nb >= 16)
	{
		len_sizet += ft_put_adress(nb / 16);
		len_sizet += ft_put_adress(nb % 16);
	}
	else
	{
		if (nb < 10)
			c = nb + 48;
		else
			c = nb - 10 + 'a';
		len_sizet += write(1, &c, 1);
	}
	return (len_sizet);
}

int	ft_putptr(size_t ptr)
{
	int	print_length;

	if (!ptr)
		return (write(1, "(nil)", 5));
	print_length = write(1, "0x", 2);
	print_length += ft_put_adress(ptr);
	return (print_length);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	e = 0;

// 	printf("[My_length]:%d\n", ft_putptr(e));
// 	printf("[Real_length]:%d", printf("%p", e));
// }
