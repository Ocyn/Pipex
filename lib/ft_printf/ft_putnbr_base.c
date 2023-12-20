/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:10:43 by jcuzin            #+#    #+#             */
/*   Updated: 2022/12/14 17:21:01 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(size_t n, int boolean, int len)
{
	char	*base;

	if (boolean == 1)
		base = "0123456789ABCDEF";
	else if (boolean == 0)
		base = "0123456789abcdef";
	else
		base = NULL;
	if (n >= 16)
		len = ft_putnbr_base(n / 16, boolean, len + 1);
	if (n < 16)
		ft_putchar(base[n % 16], len);
	else
		ft_putchar(base[n % 16], len);
	return (len);
}
