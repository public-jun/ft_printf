/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 21:36:07 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/27 17:46:45 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_n(void *dst, const void *src, size_t n)
{
	unsigned char *uc_dst;
	unsigned char *uc_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	uc_dst = (unsigned char*)dst;
	uc_src = (unsigned char*)src;
	while (n--)
	{
		*uc_dst = *uc_src;
		uc_dst++;
		uc_src++;
	}
	return (uc_dst);
}
