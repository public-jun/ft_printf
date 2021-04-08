/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:22:49 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 02:14:22 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

void			ft_branch_by_specs(t_specs_info *info, int *n, va_list *ap)
{
	if (info->specifier == 0)
		ft_print_c(info, n, ap);
	else if (info->specifier == 1)
		ft_print_s(info, n, ap);
	else if (info->specifier == 2)
		ft_print_p(info, n, ap);
	else if (info->specifier == 3)
		ft_print_di(info, n, ap);
	else if (info->specifier == 4)
		ft_print_di(info, n, ap);
	else if (5 <= info->specifier && info->specifier <= 7)
		ft_print_ux(info, n, ap);
	else
		ft_print_per(info, n);
	return ;
}

void			ft_write_n(char c, int size, int *n)
{
	unsigned	unb;

	if (*n == -1 || size <= 0)
		return ;
	unb = (unsigned)*n;
	if ((unsigned)size + unb >= INT_MAX)
	{
		*n = -1;
		return ;
	}
	*n += size;
	while (size--)
		write(1, &c, 1);
}

void			ft_putstr_ex(char *s, int s_len, int *n)
{
	unsigned	unb;

	unb = (unsigned)*n;
	if ((unsigned)s_len + unb >= INT_MAX)
	{
		*n = -1;
		return ;
	}
	write(1, s, s_len);
	*n += s_len;
}

void			print_space(t_specs_info *info, int *n, int digits, int ex)
{
	int			not_space_len;

	if (info->acc > digits)
		not_space_len = info->acc + ex;
	else
		not_space_len = digits + ex;
	if (info->field > not_space_len)
	{
		if (info->flag[1] == 0)
		{
			if (info->flag[0] == 1 && info->acc < 0)
				return ;
			ft_write_n(' ', info->field - not_space_len, n);
		}
		else
			ft_write_n(' ', info->field - not_space_len, n);
	}
}

void			print_zero(t_specs_info *info, int *n, int digits, int ex)
{
	if (info->flag[0] == 1 && info->acc < 0 && info->flag[1] == 1)
		return ;
	if (info->flag[0] == 1 && info->acc < 0)
		ft_write_n('0', info->field - (digits + ex), n);
	if (info->acc > digits)
		ft_write_n('0', info->acc - digits, n);
}
