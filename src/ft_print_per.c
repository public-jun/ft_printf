/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 00:36:59 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/25 17:18:33 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "structure.h"
#include "libft.h"

void			ft_print_per(t_specs_info *info, int *n)
{
	if (info->flag[1] == 0)
	{
		if (info->field > 1)
		{
			if (info->flag[0] == 1)
				ft_write_n('0', info->field - 1, n);
			else
				ft_write_n(' ', info->field - 1, n);
		}
		write(1, "%", 1);
		*n += 1;
	}
	else
	{
		write(1, "%", 1);
		*n += 1;
		if (info->field > 1)
			ft_write_n(' ', info->field - 1, n);
	}
}
