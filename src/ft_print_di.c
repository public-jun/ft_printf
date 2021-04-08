/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:04:06 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 02:08:07 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

int					di_count_digits(int nb)
{
	unsigned		unb;
	int				res;

	if (nb == INT_MIN)
		return (10);
	if (nb < 0)
		unb = (unsigned)(nb * -1);
	else
		unb = (unsigned)nb;
	res = 0;
	if (unb == 0)
		res++;
	while (unb != 0)
	{
		unb /= 10;
		res++;
	}
	return (res);
}

void				ft_print_neg_di(t_specs_info *info, int *n, int va_d)
{
	int				digits;

	digits = di_count_digits(va_d);
	if (info->flag[1] == 0)
		print_space(info, n, digits, 1);
	ft_write_n('-', 1, n);
	print_zero(info, n, digits, 1);
	ft_putnbr(va_d);
	*n += digits;
	if (info->flag[1] == 1)
		print_space(info, n, digits, 1);
	return ;
}

void				ft_print_di(t_specs_info *info, int *n, va_list *ap)
{
	int				va_d;
	int				digits;

	va_d = (int)va_arg(*ap, int);
	if (va_d == 0 && info->acc == 0)
		print_space(info, n, 0, 0);
	else if (va_d < 0)
		ft_print_neg_di(info, n, va_d);
	else
	{
		digits = di_count_digits(va_d);
		if (info->flag[1] == 0)
			print_space(info, n, digits, 0);
		print_zero(info, n, digits, 0);
		ft_putnbr(va_d);
		*n += digits;
		if (info->flag[1] == 1)
			print_space(info, n, digits, 0);
	}
	return ;
}
