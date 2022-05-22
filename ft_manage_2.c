/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:01:11 by odessein          #+#    #+#             */
/*   Updated: 2022/05/08 17:52:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	ft_manage_unsigned(char *str, unsigned value)
{
	int	size;
	t_Bool	add_sign;
	t_Bool	need_add;

	add_sign = false;
	need_add = false;
	size = ft_calc_number_size(str, (int) value);
	ft_apply_rules_before(str, size, &need_add);
	ft_precision(str, size, &(add_sign));
	if (ft_check_addsign(str) && !need_add)
	{
		add_sign = true;
		write(STDOUT_FILENO, "+", 1);
		size++;
	}
	ft_putnbr_unsigned(value);
	ft_apply_minus_sign(str, size);
}

void	ft_putnbr(long nb, t_Bool add_sign)
{
	if (nb < 0)
	{
		nb = nb * (-1);
		if (!add_sign)
			ft_putchar('-');
	}

	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putnbr(nb / 10, add_sign);
	ft_putchar((nb % 10) + 48);
}

void	ft_putnbr_hexa(unsigned nb)
{
	if (nb < 16)
	{
		ft_putchar(BASE_L[nb]);
		return ;
	}
	ft_putnbr_hexa(nb / 16);
	ft_putchar(BASE_L[nb % 16]);
}

void	ft_putnbr_hexa_X(unsigned nb)
{
	if (nb < 16)
	{
		ft_putchar(BASE_U[nb]);
		return ;
	}
	ft_putnbr_hexa_X(nb / 16);
	ft_putchar(BASE_U[nb % 16]);
}

void	ft_putnbr_unsigned(unsigned nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + 48);
		return ;
	}
	ft_putnbr(nb / 10, false);
	ft_putchar((nb % 10) + 48);
}
