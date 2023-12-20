/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:05:49 by jcuzin            #+#    #+#             */
/*   Updated: 2023/01/12 14:45:09 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(va_list arg_list, const char type, int len)
{
	if (type == 's')
		len = (int)ft_putstr(va_arg(arg_list, char *), len);
	if (type == 'i' || type == 'd')
		len = (int)ft_putnbr(va_arg(arg_list, int), len);
	if (type == 'c')
		len = (int)ft_putchar(va_arg(arg_list, int), len);
	if (type == 'p')
		len = (int)ft_put_adress(va_arg(arg_list, unsigned long long), len);
	if (type == 'u')
		len = (int)ft_putnbr(va_arg(arg_list, unsigned int), len);
	if (type == 'X')
	{
		len = (int)ft_putnbr_base(va_arg(arg_list, unsigned int), 1, len);
		len++;
	}
	if (type == 'x')
	{
		len = (int)ft_putnbr_base(va_arg(arg_list, unsigned int), 0, len);
		len++;
	}
	else if (type == '%')
		len = ft_putchar('%', len);
	else
		return (len);
	return (len);
}

int	ft_printf(const char *input, ...)
{
	size_t		i;
	int			len;
	va_list		arg_list;

	i = 0;
	len = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(arg_list, input);
	while (input[i])
	{
		if (input[i] == '%' && !input[i + 1])
			return (len);
		if (input[i] == '%')
		{
			++i;
			len = (int)ft_check_type(arg_list, input[i], len);
		}
		else
			len = (int)ft_putchar(input[i], len);
		i++;
	}
	va_end(arg_list);
	return (len);
}
