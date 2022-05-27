/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:34:28 by odessein          #+#    #+#             */
/*   Updated: 2022/05/26 17:29:44 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <ft_printf.h>

/*
int	ft_get_precision(char *str, t_useful *sign)
{
	int	prec;

	prec = 0;
	while ((*str && !ft_check_end(*str)) || *str == '%')
	{
		if (*str == '.' && ft_is_digit(*(str + 1)))
			prec = ft_atoi(str + 1);
		str++;
	}
	if ((*sign).need_neg)
		prec++;
	return (prec);
}
*/
t_Bool	ft_check_precision_or_not(char *str)
{
	while ((*str && !ft_check_end(*str)) || *str == '%')
	{		
		if (*str == '.')
			return (TRUE);
		str++;
	}
	return (FALSE);
}

void	ft_disp_space_neg(char *str, int size, int space, int *ret_val)
{
	int	prec;
	int	ret;

	ret = space - size;
	while (*str)
	{
		if (*str == '.' && ft_is_digit(*(str + 1)))
		{
			prec = ft_atoi(str + 1);
			if (prec < size)
				prec = size - 1;
			ret = space - (prec + 1);
			break ;
		}
		str++;
	}
	while (ret > 0)
	{
		ft_putchar(' ', ret_val);
		ret--;
	}
}

void	ft_init_struc(t_useful *init)
{
	(*init).prec = FALSE;
	(*init).need_add = FALSE;
	(*init).need_neg = FALSE;
}

void	ft_manage_hexa_v1(int *i, t_useful *sign, t_Bool *not_end, char *str)
{
	*i = 0;
	*not_end = TRUE;
	ft_init_struc(sign);
	while (str[*i] != 'x' && str[*i] != 'X' && str[*i] != '\0')
		(*i)++;
}

t_Bool ft_check_zero_or_space(char *str)
{
	while (*str && (*str == '%' || !ft_check_end(*str)))
	{
		if (*str == 0 && !ft_is_digit(*(str - 1)))
			return (TRUE);
		if (ft_is_digit(*str) && *(str - 1) != '.' 
			&& !ft_is_digit(*(str - 1)))
			return (TRUE);
		str++;
	}
	return (FALSE);
}