/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 16:11:51 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 02:17:39 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

static	char		*uptr_to_hex(uintptr_t va_p, int *digits, int *n)
{
	uintptr_t		tmp;
	char			*res;

	tmp = va_p;
	if (va_p == 0)
		*digits = 1;
	while (tmp != 0)
	{
		tmp /= 16;
		(*digits)++;
	}
	res = malloc(sizeof(char) * (*digits + 1));
	if (res == NULL)
	{
		*n = -1;
		return (NULL);
	}
	res[*digits] = '\0';
	tmp = *digits;
	while (tmp != 0)
	{
		res[--tmp] = HEX[va_p % 16];
		va_p /= 16;
	}
	return (res);
}

void				ft_print_p(t_specs_info *info, int *n, va_list *ap)
{
	uintptr_t		va_p;
	int				digits;
	char			*adr;

	va_p = (uintptr_t)va_arg(*ap, void*);
	digits = 0;
	if ((adr = uptr_to_hex(va_p, &digits, n)) == NULL)
		return ;
	if (*adr == '0' && info->acc >= 0)
		digits = 0;
	if (info->flag[1] == 0)
		print_space(info, n, digits, 2);
	ft_putstr_ex("0x", 2, n);
	print_zero(info, n, digits, 2);
	if (info->acc != 0 || *adr != '0')
		ft_putstr_ex(adr, digits, n);
	if (info->flag[1] == 1)
		print_space(info, n, digits, 2);
	ft_free_set(&adr, NULL);
	return ;
}
