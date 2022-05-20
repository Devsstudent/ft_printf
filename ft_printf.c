/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:52:20 by odessein          #+#    #+#             */
/*   Updated: 2022/05/20 19:25:03 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	va_start(ap,string);
	ft_implement((char *) string, ap);
	return (0);
}

int	main(void)
{
	ft_printf("so lets %123i see what append %f");
}

void	ft_display_specase(t_storage str)
{
	char	*string = (char *) (str->content + 1);
	
	while (!ft_check_end(string[i]))
	{
		//- work like (arg + (value after(-) - argsize) (si aucun number, its like 1)) search for the nezxt number
		//0 c'est apres 0x / les ' ' c'est avant le 0x du # xd pareil pour le +
		//precison && 0 not possible should return error ?

		if (ft_is_space)
			ft_disp(' ');
		if (ft_is_0(string[i])) //digit & 0 ||  avant; 
			ft_disp('0' * ft_grab_number(&string[i]) - size(arg/sign/or0x));
		else if (digit && avant != '.')
			ft_disp(' ' * ft_grab_number(&(string[i])) - size(arg/sign/or0x))
		if (digit && avant == '.')
			size = ft_grab_number($(string[i], 0));
		i++;
	}
}

ft_check_other(char *str)
{
	//#
	//+ 
}
