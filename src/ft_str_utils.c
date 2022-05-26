/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:58:50 by odessein          #+#    #+#             */
/*   Updated: 2022/05/25 11:58:05 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
//IDEA : Maybe just make 1 function take the char to find in params !
t_Bool	ft_check_addsign(char *str)
{
	while (*(str))
	{
		if (*str == '+')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

t_Bool	ft_check_dieze(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '#')
			return (TRUE);
		index++;
	}
	return (FALSE);
}

t_Bool	ft_is_digit(char c)
{
	if (c < 58 && c > 47)
		return (TRUE);
	return (FALSE);
}

t_Bool	ft_check_space(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '#')
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	ft_need_sign(char *str, int size, t_useful *need_add, int *ret_val)
{
	if (ft_check_addsign(str) && !((*need_add).need_neg))
	{
		ft_putchar('+', ret_val);
		size++;
		(*need_add).need_add = TRUE;
	}
	if ((*need_add).need_neg)
	{
		(*need_add).need_neg = FALSE;
		(*need_add).prec = TRUE;
		ft_putchar('-', ret_val);
	}
	return (size);
}
