/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:58:51 by odessein          #+#    #+#             */
/*   Updated: 2022/05/25 15:56:33 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
//ft_calc_number_sizeS
//ft_calc_hexa_size
	//CARE OF SIGN if negative compte it in size
	//Precison need to be calc too

void	ft_manage_int(char *str, int value, int *ret_val, t_Bool *not_end)
{
	int	size;
	t_useful	need_add;

	*not_end = TRUE;
	need_add.need_add = FALSE;
	need_add.need_neg = FALSE;
	if (value < 0)
		need_add.need_neg = TRUE;
	size = ft_calc_number_size((unsigned long) value, str);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	ft_precision(str, size, &need_add, ret_val);
	if (ft_check_neg_sign(str) && need_add.need_neg)
		ft_putchar('-', ret_val);
	if (ft_check_addsign(str) && (!need_add.need_neg && !need_add.need_add))
	{
		ft_putchar('+', ret_val);
		if (*ret_val == -1)
			return ;
		size++;
	}
	if (!ft_check_novalue(str, (unsigned int) value))
	{
		ft_putnbr((long) value, ret_val);
	}

	if (*ret_val == -1)
		return ;
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_hexa(char *str, unsigned int val, int *ret_val, t_Bool *not_end)
{
	int		size;
	char	u_or_l;
	int		i;
	t_useful	need_add;

	i = 0;
	need_add.need_add = FALSE;
	need_add.need_neg = FALSE;
	while (str[i] != 'x' && str[i] != 'X' && str[i] != '\0' )
		i++;
	if (str[i] == '\0')
		return ;
	u_or_l = str[i];
	*not_end = TRUE;
	size = ft_calc_hexa_size(str, val);
	ft_apply_rules_before(str, size, &need_add, ret_val);
	ft_precision(str, size, &need_add, ret_val);
	if (ft_check_dieze(str, 0) && val != 0)
	{
		ft_putchar('0', ret_val);
		ft_putchar('x', ret_val);
	}
	if (u_or_l == 'X' && !ft_check_novalue(str, val))
		ft_putnbr_hexa_x(val, ret_val);
	else if (u_or_l == 'x' && !ft_check_novalue(str, val))
		ft_putnbr_hexa(val, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_string(char *str, char *value, int *ret_val, t_Bool *not_end)
{
	int	size;

	*not_end = TRUE;
	size = ft_strlen_special(value, str);
	if (!str)
	{
		ft_putnstr("(null)", 6, ret_val);
		return ;
	}
	ft_apply_rules_before(str, size, FALSE, ret_val);
	ft_putnstr(value, size, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_addr(char *str, void *addr, int *ret_val, t_Bool *not_end)
{
	unsigned long	addr_conv;

	*not_end = TRUE;
	ft_apply_rules_before(str, 1, FALSE, ret_val);
	if (!addr)
	{
		ft_putnstr("(nil)", 5, ret_val);
		return ;
	}
	addr_conv = (unsigned long) addr;
	ft_putchar('0', ret_val);
	ft_putchar('x', ret_val);
	ft_putnbr_addr(addr_conv, ret_val);
	ft_apply_minus_sign(str, 1, ret_val);
}

void	ft_manage_char(char *str, char c, int *ret_val, t_Bool *not_end)
{
	*not_end = TRUE;
	ft_apply_rules_before(str, 1, FALSE, ret_val);
	ft_putchar(c, ret_val);
	ft_apply_minus_sign(str, 1, ret_val);
}
