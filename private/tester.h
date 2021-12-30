/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 01:48:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 08:19:12 by jodufour         ###   ########.fr       */
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

char	map_decrement(char const c);
char	map_increment(char const c);
char	map_mult_two(char const c);
char	map_square(char const c);
char	map_todigit(char const c);
char	map_tolower(char const c);
char	map_toupper(char const c);
char	mapi_add_i(t_uint const i, char const c);
char	mapi_decrement_odd(t_uint const i, char const c);
char	mapi_div_i(t_uint const i, char const c);
char	mapi_increment_even(t_uint const i, char const c);
char	mapi_mod_i(t_uint const i, char const c);
char	mapi_mult_i(t_uint const i, char const c);
char	mapi_sub_i(t_uint const i, char const c);

#endif
