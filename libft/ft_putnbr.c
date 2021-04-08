/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 02:06:47 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/26 02:07:22 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int nb)
{
	unsigned int	unb;
	char			n;

	if (nb < 0)
		unb = (unsigned int)(nb * -1);
	else
		unb = (unsigned int)nb;
	if (unb >= 10)
		ft_putnbr(unb / 10);
	n = (char)(unb % 10 + 48);
	write(1, &n, 1);
}
