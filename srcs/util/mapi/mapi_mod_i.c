/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapi_mod_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:50:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:47:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_int.h"

char	mapi_mod_i(t_uint const i, char const c)
{
	if (i)
		return ((t_hhuint)c % i);
	return (c);
}
