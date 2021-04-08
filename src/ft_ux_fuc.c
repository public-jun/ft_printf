/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ux_fuc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:52:43 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 01:53:24 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

int				ux_count_digits(unsigned n, unsigned base)
{
	int			digits;

	digits = 0;
	if (n == 0)
		digits = 1;
	while (n != 0)
	{
		n /= base;
		(digits)++;
	}
	return (digits);
}

char			*dec_to_base(t_specs_info *info, unsigned unb, unsigned base,
								int digits)
{
	char		*res;
	char		*n_base;

	if (info->specifier == 6)
		n_base = HEX;
	else if (info->specifier == 7)
		n_base = L_HEX;
	else
		n_base = DEC;
	res = malloc(sizeof(char) * (digits + 1));
	if (res == NULL)
		return (NULL);
	res[digits] = '\0';
	while (digits != 0)
	{
		res[--digits] = n_base[unb % base];
		unb /= base;
	}
	return (res);
}

void			ft_dec_prc(t_specs_info *info, int *n, unsigned va, int base)
{
	char		*unb;
	int			digits;

	digits = ux_count_digits(va, base);
	if ((unb = dec_to_base(info, va, base, digits)) == NULL)
	{
		ft_error_print(n);
		return ;
	}
	if (*unb == '0' && info->acc >= 0)
		digits = 0;
	if (info->flag[1] == 0)
		print_space(info, n, digits, 0);
	print_zero(info, n, digits, 0);
	if (info->acc != 0 || *unb != '0')
		ft_putstr_ex(unb, digits, n);
	if (info->flag[1] == 1)
		print_space(info, n, digits, 0);
	ft_free_set(&unb, NULL);
	return ;
}
