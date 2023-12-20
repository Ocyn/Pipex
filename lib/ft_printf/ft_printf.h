/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcuzin <jcuzin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:10:47 by jcuzin            #+#    #+#             */
/*   Updated: 2022/12/12 18:25:41 by jcuzin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_putchar(int c, int len);
int		ft_putnbr(long long nb, int len);
int		ft_put_adress(unsigned long long c, int len);
int		ft_putstr(char *str, int len);
int		ft_putnbr_base(size_t n, int boolean, int len);

#endif