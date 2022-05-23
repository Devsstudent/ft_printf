/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 19:41:43 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

void	ft_loop(char *string, va_list ap, int *ret_val)
{
	t_storage	handle;

	while (*string)
	{
		handle.content = string;
		if (*string == '%')
			string = ft_brows((char *) handle.content, ap, ret_val);
		else
		{
			ft_putchar(*string, ret_val);
			if (*ret_val == -1)
				return ;
		}
		string++;
	}
}

t_Bool	ft_check_end(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'p' || c == 's')
		return (true);
	else if (c == 'c' || c == 'x' || c == 'X' || c == '%')
		return (true);
	return (false);
}

char	*ft_brows(char *str, va_list ap, int *ret_val)
{
	int		i;
	char	*store;
	t_Bool	not_end;

	i = 0;
	not_end = false;
	store = ft_brows_1(str, ret_val);
	if (store != 0)
		return (store);
	while (str[++i] != '\0' && !not_end)
	{
		if (str[i] == 'i' || str[i] == 'd')
			ft_manage_int(str, va_arg(ap, int), ret_val, &not_end);
		else if (str[i] == 'x' || str[i] == 'X')
			ft_manage_hexa(str, va_arg(ap, unsigned), ret_val, &not_end);
		else if (str[i] == 'u')
			ft_manage_unsigned(str, va_arg(ap, unsigned), ret_val, &not_end);
		else if (str[i] == 's')
			ft_manage_string(str, va_arg(ap, char *), ret_val, &not_end);
		else if (str[i] == 'c')
			ft_manage_char(str, va_arg(ap, int), ret_val, &not_end);
		else if (str[i] == 'p')
			ft_manage_addr(va_arg(ap, void *), ret_val, &not_end);
	} 
	return (str + (--i)); 
}

char	*ft_brows_1(char *str, int *ret_val)
{
	if (str[1] == '%')
	{
		ft_putchar('%', ret_val);
		if (*ret_val == -1)
			return (str + ft_strlen(str) - 1);
		return (str + 1);
	}
	return (0);
}
