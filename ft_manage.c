/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:11:51 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 19:43:30 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

//ft_calc_number_sizeS
//ft_calc_hexa_size
	//CARE OF SIGN if negative compte it in size
	//Precison need to be calc too

void	ft_manage_int(char *str, int value, int *ret_val, t_Bool *not_end)
{
	int	size;
	t_Bool	add_sign;
	t_Bool	need_add;

	*not_end = true;
	need_add = false;
	add_sign = false;
	size = ft_calc_number_size(value);
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

void	ft_manage_hexa(char *str, unsigned int val, int *ret_val, t_Bool *not_end)
{
	int		size;
	char	u_or_l;
	int		i;

	while (str[i] != 'x' || str[i] != 'X' || str[i] != '\0' )
		i++;
	if (str[i] == '\0')
		return ;
	u_or_l = str[i];
	*not_end = true;
	size = ft_calc_hexa_size(str, val);
	ft_apply_rules_before(str, size, false, ret_val);
	ft_precision(str, size, false, ret_val);
	if (ft_check_dieze(str, 0))
	{
		ft_putchar('0', ret_val);
		ft_putchar('x', ret_val);
	}
	if (u_or_l == 'X')
		ft_putnbr_hexa_x(val, ret_val);
	else
		ft_putnbr_hexa(val, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_string(char *str, char *value, int *ret_val, t_Bool *not_end)
{
	int	size;

	*not_end = true;
	size = ft_strlen_special(value, str);
	ft_apply_rules_before(str, size, false, ret_val);
	ft_putnstr(value, size, ret_val);
	ft_apply_minus_sign(str, size, ret_val);
}

void	ft_manage_addr(void *addr, int *ret_val, t_Bool *not_end)
{
	unsigned long	addr_conv;

	*not_end = true;
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

void	ft_manage_char(char *str, char c, int *ret_val, t_Bool *not_end)
{
	*not_end = true;
	ft_apply_rules_before(str, 1, false, ret_val);
	ft_putchar(c, ret_val);
	ft_apply_minus_sign(str, 1, ret_val);
}
