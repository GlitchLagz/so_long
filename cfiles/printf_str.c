/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:13:36 by tpawson           #+#    #+#             */
/*   Updated: 2023/04/17 01:43:01 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static void	ft_ptstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int	printf_ptstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_ptstr("(null)");
		return (6);
	}
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return (i);
}
