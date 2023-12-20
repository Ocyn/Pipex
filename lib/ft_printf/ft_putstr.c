/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:25:23 by jcuzin            #+#    #+#             */
/*   Updated: 2022/12/14 15:12:44 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str, int len)
{
	int		i;

	i = 0;
	if (!str)
	{
		len += 6;
		write(1, "(null)", 6);
		return (len);
	}
	while (str[i])
	{
		len = ft_putchar(str[i], len);
		i++;
	}
	return (len);
}
