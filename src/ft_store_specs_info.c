/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_specs_info.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:16:52 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/27 17:11:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

void				ft_store_flag(const char **fmt, t_specs_info *info)
{
	int				type_index;

	while (**fmt && (type_index = ft_get_type_index("0-", **fmt)) >= 0)
	{
		info->flag[type_index] = 1;
		(*fmt)++;
	}
}

void				ft_store_field(const char **fmt, t_specs_info *info,
									va_list *ap)
{
	int				va_field;

	va_field = 0;
	if (**fmt == '*')
	{
		va_field = (int)va_arg(*ap, int);
		info->field = va_field;
		if (info->field < 0 && va_field != INT_MIN)
		{
			info->flag[1] = 1;
			info->field *= -1;
		}
		(*fmt)++;
	}
	else if ('1' <= (**fmt) && (**fmt) <= '9')
	{
		info->field = 0;
		while ('0' <= (**fmt) && (**fmt) <= '9')
		{
			info->field = (info->field) * 10 + ((**fmt) - '0');
			(*fmt)++;
		}
	}
}

void				ft_store_acc(const char **fmt, t_specs_info *info,
								va_list *ap)
{
	int				va_acc;

	if ((**fmt) == '.')
	{
		(*fmt)++;
		info->acc = 0;
		if (**fmt == '*' || **fmt == '-')
		{
			va_acc = (int)va_arg(*ap, int);
			info->acc = va_acc;
			if (va_acc < 0 || **fmt == '-')
				info->acc = -1;
			(*fmt)++;
			return ;
		}
		while ('0' <= (**fmt) && (**fmt) <= '9')
		{
			info->acc = (info->acc) * 10 + ((**fmt) - '0');
			(*fmt)++;
		}
	}
}

void				ft_store_specs(const char **fmt, t_specs_info *info)
{
	int				specs_index;

	specs_index = -1;
	if ((specs_index = ft_get_type_index("cspdiuxX%", **fmt)) >= 0)
	{
		info->specifier = specs_index;
		(*fmt)++;
	}
}
