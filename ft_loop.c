/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:51:26 by odessein          #+#    #+#             */
/*   Updated: 2022/05/23 15:21:29 by odessein         ###   ########.fr       */
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
	char	type;
	int	i;
	t_Bool	not_end;

	i = 1;
	not_end = false;
	if (ft_handle_err(str, ret_val))
		return (&str[(int) ft_strlen(str) - 1]);
	if (str[i] == '%')
	{
		ft_putchar('%', ret_val);
		if (*ret_val == -1)
			return (str + ft_strlen(str) - 1);
		return (str + i);
	}
	while (str[i] != '\0' && !not_end)
	{
//		printf("%c", str[i]);
		if (str[i] == 'i' || str[i] == 'd')
		{
			ft_manage_int(str, va_arg(ap, int), ret_val);
			not_end = true;
		}
		else if (str[i] == 'x' || str[i] == 'X')
		{
			ft_manage_hexa(str, va_arg(ap, unsigned), str[i], ret_val);
			not_end = true;
		}
		else if (str[i] == 'u')
		{
			ft_manage_unsigned(str, va_arg(ap, unsigned), ret_val);
			not_end = true;
		}
		else if (str[i] == 's')
		{
			ft_manage_string(str, va_arg(ap, char*), ret_val);
			not_end = true;
		}
		else if (str[i] == 'c')
		{
			ft_manage_char(str, va_arg(ap, int), ret_val);
			not_end = true;
		}
		else if (str[i] == 'p')
		{
			ft_manage_addr(str, va_arg(ap, void*), ret_val);
			not_end = true;
		}
		i++; 
	} 
	return (str + (--i)); 
}

	// -1) Special case ( +-# or number)

	// -2) Get the value in ap from the last letter of content (3 possibilies) a lot of if;

		// -3) Deal with value to display depending on 3last digit(.(digit)(letter)) -> a lot of function of display with like a parameters of size

//	ft_fill_struc(str, ap); -> handle type et convert to value depending of %  si y a un point . on lit la valeur suivante 
	//size de tout pour pouvoir comparer avec les size demander. ou bien des size params genre atoi qui compte les tours etc	 
//	ft_special_case(str); (+- #0)
//	display value in struct. depending of the type maybe an enum to store it or something,

