/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:33:26 by odessein          #+#    #+#             */
/*   Updated: 2022/05/19 16:35:48 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H 
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define BASE_L "0123456780abcdef"
# define BASE_U "0123456780ABCDEF"

typedef enum {
	false = 0,
	true = 1
}	t_Bool;

typedef struct s_storage {
	void					*content;
	t_Bool					space_after;
}							t_storage;

t_Bool	ft_check_end(char c);
void	ft_implement(char *string, va_list ap);
int	ft_power(long number, int power);

#endif
