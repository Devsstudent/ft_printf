/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:30:21 by odessein          #+#    #+#             */
/*   Updated: 2022/05/26 17:40:41 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putnbr_unsigned(unsigned int nb, int *ret_val)
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

void	ft_manage_unsigned(char *str, unsigned int val, int *r_v, t_Bool *n_en)
{
	int			size;
	t_useful	need_add;

	*n_en = TRUE;
	ft_init_struc(&need_add);
	size = ft_calc_number_size((unsigned long) val, str);
	ft_apply_rules_before(str, size, &need_add, r_v);
	ft_precision(str, size, &need_add, r_v);
	if (ft_check_addsign(str) && !need_add.need_add)
	{
		ft_putchar('+', r_v);
		if (*r_v == -1)
			return ;
		size++;
	}
	if (!ft_check_novalue(str, val))
	{
		ft_putnbr_unsigned(val, r_v);
		if (*r_v == -1)
			return ;
	}
	ft_apply_minus_sign(str, size, r_v, &need_add);
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
