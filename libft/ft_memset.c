/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 15:16:16 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/14 09:36:08 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = b;
	while (len--)
		*(ptr++) = (unsigned char)c;
	return (b);
}

void	*ft_get_n_ptr_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = b;
	while (len--)
		*(ptr++) = (unsigned char)c;
	return (ptr);
}
