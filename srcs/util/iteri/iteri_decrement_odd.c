/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteri_decrement_odd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:00:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:46:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

void	iteri_decrement_odd(t_uint const i, char *const c)
{
	*(t_hhuint *)c -= (i % 2U);
}
