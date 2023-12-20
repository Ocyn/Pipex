/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:11:02 by jcuzin            #+#    #+#             */
/*   Updated: 2022/12/14 17:05:33 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_adress(unsigned long long c, int len)
{
	len = ft_putstr("0x", len);
	len = ft_putnbr_base(((size_t)c), 0, len);
	return (len + 1);
}
