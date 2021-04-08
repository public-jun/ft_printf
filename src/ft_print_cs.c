/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:23:51 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 02:00:15 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

void			ft_print_c(t_specs_info *info, int *n, va_list *ap)
{
	char		va_c;

	va_c = (char)va_arg(*ap, int);
	if (info->flag[1] == 0)
	{
		if (info->field > 1)
		{
			if (info->flag[0] == 1)
				ft_write_n('0', info->field - 1, n);
			else
				ft_write_n(' ', info->field - 1, n);
		}
		ft_putstr_ex(&va_c, 1, n);
	}
	else
	{
		ft_putstr_ex(&va_c, 1, n);
		if (info->field > 1)
			ft_write_n(' ', info->field - 1, n);
	}
}

void			ft_print_s(t_specs_info *info, int *n, va_list *ap)
{
	char		*va_s;
	int			s_len;

	va_s = (char*)va_arg(*ap, char*);
	if (va_s == NULL)
		va_s = "(null)";
	s_len = (int)ft_strlen(va_s);
	if (info->acc >= 0 && info->acc < s_len)
		s_len = info->acc;
	if (info->flag[1] == 0)
	{
		if (info->field > s_len && info->field > 0)
		{
			if (info->flag[0] == 0)
				ft_write_n(' ', info->field - s_len, n);
			else
				ft_write_n('0', info->field - s_len, n);
		}
	}
	ft_putstr_ex(va_s, s_len, n);
	if (info->flag[1] == 1 && info->field > s_len && info->field > 0)
		ft_write_n(' ', info->field - s_len, n);
}
