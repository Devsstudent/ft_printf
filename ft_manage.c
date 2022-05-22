/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:51 by odessein          #+#    #+#             */
/*   Updated: 2022/05/21 14:55:21 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

//ft_calc_number_sizeS
//ft_calc_hexa_size
	//CARE OF SIGN if negative compte it in size
	//Precison need to be calc too

void	ft_manage_int(char *str, int value)
{
	int	size;
	t_Bool	add_sign;
	t_Bool	need_add;

	need_add = false;
	add_sign = false;
	size = ft_calc_number_size(str, value);
	ft_apply_rules_before(str, size, &need_add);
	ft_precision(str, size, &need_add);
	if (ft_check_addsign(str) && !need_add)
	{
		add_sign = true;
		write(1, "+", 1);
		size++;
	}
	ft_putnbr((long) value, add_sign);
	ft_apply_minus_sign(str, size);
}

void	ft_manage_hexa(char *str, unsigned value, char u_or_l)
{
	int	size;

	size = ft_calc_hexa_size(str, value);
	ft_apply_rules_before(str, size, false);
	ft_precision(str, size, false);
	if (ft_check_dieze(str, 0))
	{
		ft_putchar('0');
		ft_putchar('x');
	}
	if (u_or_l == 'X')
		ft_putnbr_hexa_X(value);
	else
		ft_putnbr_hexa(value);
	ft_apply_minus_sign(str, size);
	//ft_putnbr_hexa_conv
}

//ICI care precision reduction works on string (otherwiser not working)
//Need to make a special rules for it

void	ft_manage_string(char *str, char *value)
{
	int	size;

	size = ft_strlen_special(value, str);
	ft_apply_rules_before(str, size, false);
	ft_putnstr(value, size);
	ft_apply_minus_sign(str, size);
}

void	ft_manage_addr(char *str, void *addr)
{
	unsigned long	addr_conv;
	addr_conv = (unsigned long) addr;
	ft_putchar('0');
	ft_putchar('x');
	ft_putnbr_hexa(addr_conv);
}

void	ft_manage_char(char *str, char c)
{
	ft_apply_rules_before(str, 1, false);
	ft_putchar(c);
	ft_apply_minus_sign(str, 1);
}
