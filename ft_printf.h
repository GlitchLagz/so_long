/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:56:12 by tpawson           #+#    #+#             */
/*   Updated: 2023/06/14 18:22:11 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		printf_char(int c);
int		printf_ptstr(char *str);
int		printf_ptint(int nb);
int		printf_pt_unint(unsigned int un);
int		printf_pthex(unsigned int nb, const char format);
int		printf_ptr(unsigned long long ptr);
int		printf_pt_pcent(void);

char	*ft_itoa(int n);

#endif
