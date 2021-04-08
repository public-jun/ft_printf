/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:33:21 by jnakahod          #+#    #+#             */
/*   Updated: 2021/04/08 15:54:35 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>


int			main(void)
{
	int n;

	n = printf("%10.*s", 5, "abc");
	printf("\n%d\n", n);
	system("leaks a.out");
	//printf("sizeof :char* = %lu\n", sizeof(char*));
	//printf("sizeof :p = %lu\n", p);
	/*
	n = 0;
	puts("abcd%*d");
	n = ft_printf("abcd%*d\n", 10);
	puts("abcd%12345.*s");
	n = ft_printf("abcd%12345.*s\n", 15);
	puts("abcd%*.*d");
	n = ft_printf("abcd%*.*d\n", 10, 15);
	puts("abcd%0.0i");
	n = ft_printf("abcd%0.0i\n");
	puts("abcd%-.01x");
	n = ft_printf("abcd%-.01x\n");
	puts("abcd%-123.100X");
	n = ft_printf("abcd%-123.100X\n");
	puts("abcd%005d");
	n = ft_printf("abcd%005d");

	puts("---no_specifier--------");
	n = ft_printf("%ab\n");
	printf("%d", n);

	*/
	
	return (0);
}
