/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:27:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 16:20:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	STRDUP_ERR,
	STRNDUP_ERR,
	FT_SPLIT_ERR,
	FT_STRDUP_ERR,
	FT_STRMAP_ERR,
	FT_SUBSTR_ERR,
	FT_STRCDUP_ERR,
	FT_STRNDUP_ERR,
	FT_STRJOIN_ERR,
	FT_STRLINK_ERR,
	FT_STRTRIM_ERR,
	FT_STRCJOIN_ERR,
	FT_STRSUBCHR_ERR,
	FT_STRSUBIDX_ERR
};

#endif
