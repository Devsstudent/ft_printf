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

typedef enum {
	false = 0,
	true = 1
}	t_Bool;

typedef struct s_string_list {
	char					*content;
	t_Bool					to_calc;
	char					c;
	long long int			nb;
	char					*str;
	struct s_string_list	*next;
}							t_str_l;

t_Bool	ft_check_end(char c);
void	ft_implement(char *string, va_list ap);

#endif
