/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:30:09 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 02:18:23 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

void			ft_print_ux(t_specs_info *info, int *n, va_list *ap)
{
	unsigned	va;
	int			base;

	if (info->specifier == 6 || info->specifier == 7)
		base = 16;
	else
		base = 10;
	va = (unsigned)va_arg(*ap, unsigned);
	ft_dec_prc(info, n, va, base);
	return ;
}
