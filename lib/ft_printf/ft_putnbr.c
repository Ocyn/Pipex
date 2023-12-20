/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:08:36 by jcuzin            #+#    #+#             */
/*   Updated: 2022/12/12 14:08:27 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long nb, int len)
{
	unsigned int	n;

	if (nb < 0)
	{
		len = ft_putchar('-', len);
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		len = ft_putnbr(n / 10, len);
		n %= 10;
	}
	len = ft_putchar(n + '0', len);
	return (len);
}
