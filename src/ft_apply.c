/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:47:13 by odessein          #+#    #+#             */
/*   Updated: 2022/05/25 15:54:54 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

void	ft_apply_rules_before(char *str, int size, t_useful *sign, int *ret_val)
{
	int	i;

	i = 1;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == ' ' && str[i + 1] != '0')
		{
			ft_putchar(' ', ret_val);
			if (*ret_val == -1)
				return ;
		}
		if (ft_is_digit(str[i]) && !ft_check_minus(str) && str[i] != '0')
			i = ft_disp_space(str, size, i, ret_val);
		if (str[i] == '0' && !ft_check_end(str[i + 1]))
		{
			size = ft_need_sign(str, size, sign, ret_val);
			if (ft_is_digit(str[i + 1]))
				i = ft_disp_zero(str, size, i + 1, ret_val);
		}
		if (str[i] == '.' || ft_check_end(str[i]))
			return ;
		i++;
	}
}

void	ft_apply_minus_sign(char *str, int size, int *ret_val)
{
	int	i;

	i = 1;
	if (ft_check_space(str, 0))
		size++;
	
	while (!(ft_check_end(str[i])))
	{
		if (str[i] == '-' && ft_is_digit(str[i + 1]))
		{
			ft_disp_space(str, size, i + 1, ret_val);
			if (*ret_val == -1)
				return ;
		}
		i++;
	}
}

void	ft_precision(char *str, int size, t_useful *add_sign, int *ret_val)
{
	int		nb_of_zero;
	int		i;

	i = 1;
	while (!ft_check_end(str[i]))
	{
		if (str[i] == '.')
		{
			if (ft_check_prec_zero(str))
				size = ft_need_sign(str, size, add_sign, ret_val);
			if (ft_is_digit(str[i+ 1]))
			{
				nb_of_zero = ft_atoi(&str[i + 1]) - size;
				while (nb_of_zero > 0)
				{
					ft_putchar('0', ret_val);
					if (*ret_val == -1)
						return ;
					nb_of_zero--;
				}
				return ;
			}
		}
		i++;
	}
}

int	ft_disp_zero(char *str, int size, int index, int *ret_val)
{
	//atoi un sub str pour avoir la value de buf_index
	int		nb_of_zero;
	int		index_cursor;

	// function qui check if a space before index if it is print 1 less 0
	index_cursor = index;
	if (ft_check_space(str, index))
		size++;
	while (ft_is_digit(str[index_cursor]))
		index_cursor++;
	nb_of_zero = ft_atoi(&str[index]) - size;
	nb_of_zero = ft_check_precision(str, nb_of_zero, size);
	while (nb_of_zero > 0)
	{
		ft_putchar('0', ret_val);
		if (*ret_val == -1)
			return (ft_strlen(str) - 1);
		nb_of_zero--;
	}
	return (index_cursor);
}

int	ft_disp_space(char *str, int size, int index, int *ret_val)
{
	int		nb_of_space;

	nb_of_space = ft_atoi(&str[index]) - size;
	nb_of_space = ft_check_precision(str, nb_of_space, size);
	while (nb_of_space > 0)
	{
		ft_putchar(' ', ret_val);
		if (*ret_val == -1)
			return (ft_strlen(str) - 1);
		nb_of_space--;
	}
	while (ft_is_digit(str[index]))
		index++;
	return (index);
}
