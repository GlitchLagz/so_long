/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_un_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:13:19 by tpawson           #+#    #+#             */
/*   Updated: 2023/04/17 01:42:14 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

static size_t	ft_un_int_len(unsigned int nb)
{
	size_t	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static char	*ft_unitoa(unsigned int n)
{
	char	*nb;
	size_t	len;

	len = ft_un_int_len(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (NULL);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + 48;
		n /= 10;
		--len;
	}
	return (nb);
}

int	printf_pt_unint(unsigned int un)
{
	int		pt_len;
	char	*nb;

	pt_len = 0;
	if (un == 0)
		pt_len += write(1, "0", 1);
	else
	{
		nb = ft_unitoa(un);
		pt_len += printf_ptstr(nb);
		free(nb);
	}
	return (pt_len);
}
