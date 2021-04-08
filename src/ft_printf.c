/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 14:19:23 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/28 12:52:13 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

static void			ft_init_specs_info(t_specs_info *info)
{
	info->flag[0] = 0;
	info->flag[1] = 0;
	info->field = -1;
	info->acc = -1;
	info->specifier = -1;
}

static int			ft_check_info(t_specs_info *info, int *n)
{
	long long f;
	long long a;

	f = (long long)info->field;
	a = (long long)info->acc;
	if (f > 0)
		f *= -1;
	if (a > 0)
		a *= -1;
	if (f <= INT_MIN + 1 || a <= INT_MIN + 1)
	{
		ft_error_print(n);
		return (-1);
	}
	return (0);
}

static void			ft_prc_per(const char **fmt, const char **start,
								int *n, va_list *ap)
{
	t_specs_info	specs_info;

	(*fmt)++;
	ft_init_specs_info(&specs_info);
	ft_store_flag(fmt, &specs_info);
	ft_store_field(fmt, &specs_info, ap);
	ft_store_acc(fmt, &specs_info, ap);
	ft_store_specs(fmt, &specs_info);
	if (ft_check_info(&specs_info, n) == -1)
		return ;
	if (specs_info.specifier == -1)
	{
		(*start)++;
		write(2, *start, *fmt - *start);
		*n += *fmt - *start;
		return ;
	}
	ft_branch_by_specs(&specs_info, n, ap);
}

static void			ft_print_str(const char **start, const char **fmt, int *n)
{
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	*n += (*fmt - *start);
}

int					ft_printf(const char *fmt, ...)
{
	int				n;
	va_list			ap;
	const char		*start;

	n = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		return (-1);
	while (n >= 0 && *fmt)
	{
		start = fmt;
		if (*start != '%')
			ft_print_str(&start, &fmt, &n);
		else
			ft_prc_per(&fmt, &start, &n, &ap);
	}
	va_end(ap);
	return (n);
}
