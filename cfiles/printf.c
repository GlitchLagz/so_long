/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:38:34 by tpawson           #+#    #+#             */
/*   Updated: 2023/04/17 02:52:41 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static int	format_eval(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += printf_char(va_arg(args, int));
	else if (format == 'u')
		len += printf_pt_unint(va_arg(args, unsigned int));
	else if (format == 'X' || format == 'x')
		len += printf_pthex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += printf_ptr(va_arg(args, unsigned long long));
	else if (format == 's')
		len += printf_ptstr(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += printf_ptint(va_arg(args, int));
	else if (format == '%')
		len += printf_pt_pcent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		t_len;
	va_list	args;

	va_start(args, format);
	i = 0;
	t_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
			t_len += format_eval(args, format[++i]);
		else
			t_len += printf_char(format[i]);
		i++;
	}
	va_end(args);
	return (t_len);
}
