/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:12:55 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 14:56:01 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

t_Bool	ft_handle_err(char *str, int *ret_val)
{
	str++;
	if (*str == ' ')
		str++;
	if (*str == '+')
		str++;
	if (*str == 0)
		str++;
	while(ft_is_digit(*str))
		str++;
	if (*str == '-')
	{
		str++;
		while (ft_is_digit(*str))
			str++;
	}
	if (*str == '.')
	{
		str++;
		while (ft_is_digit(*str))
			str++;
	}
	if (!ft_check_end(*str))
	{
		*ret_val = -1;
		return (true);
	}
	return (false);
}
/*
void	ft_check_comb_nb(char *str, t_Bool *error)
{
	
}

void	ft_check_comb_hex(char *str, t_Bool *error)
{

}

void	ft_check_comb_string(char *str, t_Bool *error)
{

}

void	ft_check_comb_addr(char *str, t_Bool *error)
{

}
*/
