/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:52:20 by odessein          #+#    #+#             */
/*   Updated: 2022/05/19 18:14:30 by odessein         ###   ########.fr       */
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
	ft_printf("so lets %   i see what appemnd %f");
}
