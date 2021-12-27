/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:27:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/27 18:36:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_LOOKUP_H
# define ERR_MSG_LOOKUP_H

# include "enum/e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const	err;
	char const	*msg;
};

static t_err_msg const		g_err_msg[] = {
{STRDUP_ERR, "strdup() failed"},
{FT_SPLIT_ERR, "ft_split() failed"},
{FT_STRDUP_ERR, "ft_strdup() failed"},
{FT_STRCDUP_ERR, "ft_strcdup() failed"},
{FT_STRJOIN_ERR, "ft_strjoin() failed"},
{FT_STRCJOIN_ERR, "ft_strcjoin() failed"},
{0}
};

#endif
