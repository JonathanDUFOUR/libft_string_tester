/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteri_decrement_odd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:00:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 18:15:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

void	iteri_decrement_odd(t_uint const i, char *const c)
{
	*(t_hhuint *)c -= (i % 2U);
}
