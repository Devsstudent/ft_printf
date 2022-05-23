/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:51 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 15:17:29 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

//ft_calc_number_sizeS
//ft_calc_hexa_size
	//CARE OF SIGN if negative compte it in size
	//Precison need to be calc too

void	ft_manage_int(char *str, int value, int *ret_val)
{
	int	size;
	t_Bool	add_sign;
	t_Bool	need_add;

	need_add = false;
	add_sign = false;
	size = ft_calc_number_size(str, value);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	ft_precision(str, size, &need_add, ret_val);
	if (ft_check_addsign(str) && !need_add)
	{
		add_sign = true;
		ft_putchar('+', ret_val);
		size++;
	}
	ft_putnbr((long) value, add_sign, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_hexa(char *str, unsigned value, char u_or_l, int *ret_val)
{
	int	size;

	size = ft_calc_hexa_size(str, value);
	ft_apply_rules_before(str, size, false, ret_val);
	ft_precision(str, size, false, ret_val);
	if (ft_check_dieze(str, 0))
	{
		ft_putchar('0', ret_val);
		ft_putchar('x', ret_val);
	}
	if (u_or_l == 'X')
		ft_putnbr_hexa_X(value, ret_val);
	else
		ft_putnbr_hexa(value, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

//ICI care precision reduction works on string (otherwiser not working)
//Need to make a special rules for it

void	ft_manage_string(char *str, char *value, int *ret_val)
{
	int	size;

	size = ft_strlen_special(value, str);
	ft_apply_rules_before(str, size, false, ret_val);
	ft_putnstr(value, size, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_addr(char *str, void *addr, int *ret_val)
{
	unsigned long	addr_conv;

	if (!addr)
	{
		ft_putnstr("(nil)", 5, ret_val);
		return ;
	}
	addr_conv = (unsigned long) addr;
	ft_putchar('0', ret_val);
	ft_putchar('x', ret_val);
	ft_putnbr_hexa(addr_conv, ret_val);
}

void	ft_manage_char(char *str, char c, int *ret_val)
{
	ft_apply_rules_before(str, 1, false, ret_val);
	ft_putchar(c, ret_val);
	ft_apply_minus_sign(str, 1, ret_val);
}
