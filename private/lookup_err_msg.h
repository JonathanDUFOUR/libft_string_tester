/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_err_msg.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:27:29 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:41:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_ERR_MSG_H
# define LOOKUP_ERR_MSG_H

# include "e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const	err;
	char const	*msg;
};

static t_err_msg const		g_err_msg[] = {
{STRDUP_ERR, "strdup() failed"},
{STRNDUP_ERR, "strndup() failed"},
{FT_SPLIT_ERR, "ft_split() failed"},
{FT_STRDUP_ERR, "ft_strdup() failed"},
{FT_STRMAP_ERR, "ft_strmap() failed"},
{FT_SUBSTR_ERR, "ft_substr() failed"},
{FT_STRCDUP_ERR, "ft_strcdup() failed"},
{FT_STRNDUP_ERR, "ft_strndup() failed"},
{FT_STRJOIN_ERR, "ft_strjoin() failed"},
{FT_STRLINK_ERR, "ft_strlink() failed"},
{FT_STRTRIM_ERR, "ft_strtrim() failed"},
{FT_STRCJOIN_ERR, "ft_strcjoin() failed"},
{FT_STRSUBCHR_ERR, "ft_strsubchr() failed"},
{FT_STRSUBIDX_ERR, "ft_strsubidx() failed"},
{0}
};

#endif
