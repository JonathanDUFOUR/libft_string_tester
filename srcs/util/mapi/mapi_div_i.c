/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapi_div_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:49:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 08:39:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

char	mapi_div_i(t_uint const i, char const c)
{
	if (i)
		return ((t_hhuint)c / i);
	return (c);
}
