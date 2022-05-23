/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:01:11 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 12:10:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	ft_manage_unsigned(char *str, unsigned value, int *ret_val)
{
	int	size;
	t_Bool	add_sign;
	t_Bool	need_add;

	add_sign = false;
	need_add = false;
	size = ft_calc_number_size(str, (int) value);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	ft_precision(str, size, &(add_sign), ret_val);
	if (ft_check_addsign(str) && !need_add)
	{
		add_sign = true;
		ft_putchar('+', ret_val);
		if (*ret_val == -1)
			return ;
		size++;
	}
	ft_putnbr_unsigned(value, ret_val);
	if (*ret_val == -1)
		return ;
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_putnbr(long nb, t_Bool add_sign, int *ret_val)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		if (!add_sign)
			ft_putchar('-', ret_val);
	}

	if (nb < 10)
	{
		ft_putchar(nb + 48, ret_val);
		return ;
	}
	ft_putnbr(nb / 10, add_sign, ret_val);
	ft_putchar((nb % 10) + 48, ret_val);
	if (*ret_val == -1)
		return ;
}

void	ft_putnbr_hexa(unsigned nb, int *ret_val)
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

void	ft_putnbr_hexa_X(unsigned nb, int *ret_val)
{
	if (nb < 16)
	{
		ft_putchar(BASE_U[nb], ret_val);
		return ;
	}
	ft_putnbr_hexa_X(nb / 16, ret_val);
	ft_putchar(BASE_U[nb % 16], ret_val);
	if (*ret_val == -1)
		return ;
}

void	ft_putnbr_unsigned(unsigned nb, int *ret_val)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48, ret_val);
		return ;
	}
	ft_putnbr(nb / 10, false, ret_val);
	ft_putchar((nb % 10) + 48, ret_val);
	if (*ret_val == -1)
		return ;
}
