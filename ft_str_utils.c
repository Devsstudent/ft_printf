/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:58:50 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 11:52:43 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"
//IDEA : Maybe just make 1 function take the char to find in params !
t_Bool	ft_check_addsign(char *str)
{
	while (*(str))
	{
		if (*str == '+')
			return (true);
		str++;
	}
	return (false);
}

t_Bool	ft_check_dieze(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '#')
			return (true);
		index++;
	}
	return (false);
}

t_Bool	ft_is_digit(char c)
{
	if (c < 58 && c > 47)
		return (true);
	return (false);
}

t_Bool	ft_check_space(char *str, int index)
{
	while (str[index])
	{
		if (str[index] == '#')
			return (true);
		index++;
	}
	return (false);
}

int	ft_need_sign(char *str, int size, t_Bool *need_add, int *ret_val)
{
	if (ft_check_addsign(str))
	{
		ft_putchar('+', ret_val);
		size++;
		*need_add = true;
	}
	return (size);
}
