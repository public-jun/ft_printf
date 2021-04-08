/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 16:16:20 by jnakahod          #+#    #+#             */
/*   Updated: 2020/12/27 17:45:32 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include "structure.h"

# define HEX "0123456789abcdef"
# define L_HEX "0123456789ABCDEF"
# define DEC "0123456789"

int				ft_printf(const char *fmt, ...);
void			ft_error_print(int *n);
void			ft_branch_by_specs(t_specs_info *info, int *n, va_list *ap);
void			ft_print_c(t_specs_info *info, int *n, va_list *ap);
void			ft_store_flag(const char **fmt, t_specs_info *info);
void			ft_store_field(const char **fmt, t_specs_info *info,
								va_list *ap);
void			ft_store_acc(const char **fmt, t_specs_info *info,
								va_list *ap);
void			ft_store_specs(const char **fmt, t_specs_info *info);
void			ft_write_n(char c, int size, int *n);
void			ft_print_s(t_specs_info *info, int *n, va_list *ap);
void			ft_print_p(t_specs_info *info, int *n, va_list *ap);
void			print_space(t_specs_info *info, int *n, int digits, int ex);
void			print_zero(t_specs_info *info, int *n, int digits, int ex);
void			ft_print_per(t_specs_info *info, int *n);
void			ft_print_di(t_specs_info *info, int *n, va_list *ap);
void			ft_putnbr(int nb);
void			ft_putstr_ex(char *s, int s_len, int *n);
void			ft_print_ux(t_specs_info *info, int *n, va_list *ap);
char			*dec_to_base(t_specs_info *info, unsigned unb, unsigned base,
								int digits);
int				ux_count_digits(unsigned n, unsigned base);
void			ft_dec_prc(t_specs_info *info, int *n, unsigned va, int base);
#endif
