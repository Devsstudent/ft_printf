/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   ft_manage_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:01:11 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 19:44:56 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	ft_manage_unsigned(char *str, unsigned int value, int *ret_val, t_Bool *not_end)
{
	int		size;
	t_useful	need_add;

	*not_end = TRUE;
	need_add.need_add = FALSE;
	need_add.need_neg = FALSE;
	size = ft_calc_number_size((unsigned long) value, str);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	ft_precision(str, size, &need_add, ret_val);
	if (ft_check_addsign(str) && !need_add.need_add)
	{
		ft_putchar('+', ret_val);
		if (*ret_val == -1)
			return ;
		size++;
	}
	if (!ft_check_novalue(str, value))
	{
		ft_putnbr_unsigned(value, ret_val);
		if (*ret_val == -1)
			return ;
	}
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_putnbr(long nb, int *ret_val)
{
	if (nb < 0)
		nb = nb * (-1);
	if (nb < 10)
	{
		ft_putchar(nb + 48, ret_val);
		return ;
	}
	ft_putnbr(nb / 10, ret_val);
	ft_putchar((nb % 10) + 48, ret_val);
	if (*ret_val == -1)
		return ;
}

void	ft_putnbr_hexa(unsigned int nb, int *ret_val)
{
	if (nb < 16)
	{
		ft_putchar(BASE_L[nb], ret_val);
		return ;
	}
	ft_putnbr_hexa(nb / 16, ret_val);
	ft_putchar(BASE_L[nb % 16], ret_val);
	if (*ret_val == -1)
		return ;
}

void	ft_putnbr_hexa_x(unsigned int nb, int *ret_val)
{
	if (nb < 16)
	{
		ft_putchar(BASE_U[nb], ret_val);
		return ;
	}
	ft_putnbr_hexa_x(nb / 16, ret_val);
	ft_putchar(BASE_U[nb % 16], ret_val);
	if (*ret_val == -1)
		return ;
}

void	ft_putnbr_unsigned(unsigned int nb, int *ret_val)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48, ret_val);
		return ;
	}
	ft_putnbr(nb / 10, ret_val);
	ft_putchar((nb % 10) + 48, ret_val);
	if (*ret_val == -1)
		return ;
}
