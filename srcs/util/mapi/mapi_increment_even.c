/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapi_increment_even.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:59:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 08:40:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

char	mapi_increment_even(t_uint const i, char const c)
{
	return ((t_hhuint)c + !(i % 2U));
}
