/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapi_decrement_odd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:00:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:47:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

char	mapi_decrement_odd(t_uint const i, char const c)
{
	return ((t_hhuint)c - (i % 2U));
}
