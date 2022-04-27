/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteri_increment_even.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:59:03 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:46:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

void	iteri_increment_even(t_uint const i, char *const c)
{
	*(t_hhuint *)c += !(i % 2U);
}
