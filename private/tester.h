/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:48:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 15:02:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# include "type/t_int.h"

int		err_msg(int const err);

void	iter_decrement(char *const c);
void	iter_increment(char *const c);
void	iter_mult_two(char *const c);
void	iter_square(char *const c);
void	iter_todigit(char *const c);
void	iter_tolower(char *const c);
void	iter_toupper(char *const c);
void	iteri_add_i(t_uint const i, char *const c);
void	iteri_decrement_odd(t_uint const i, char *const c);
void	iteri_div_i(t_uint const i, char *const c);
void	iteri_increment_even(t_uint const i, char *const c);
void	iteri_mod_i(t_uint const i, char *const c);
void	iteri_mult_i(t_uint const i, char *const c);
void	iteri_sub_i(t_uint const i, char *const c);
void	result(int const num, int const res);

#endif
