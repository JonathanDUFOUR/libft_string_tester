/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapi_decrement_odd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:00:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 08:38:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

char	mapi_decrement_odd(t_uint const i, char const c)
{
	return ((t_hhuint)c - (i % 2U));
}
