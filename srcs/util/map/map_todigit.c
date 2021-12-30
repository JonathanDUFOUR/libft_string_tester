/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_todigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:24:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/30 08:23:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>

typedef struct s_lookup	t_lookup;

struct s_lookup
{
	char const	alpha;
	char const	digit;
};

static t_lookup const	g_lookup[] = {
{'o', '0'},
{'i', '1'},
{'z', '2'},
{'e', '3'},
{'a', '4'},
{'s', '5'},
{'g', '6'},
{'t', '7'},
{'b', '8'},
{'q', '9'},
{0}
};

char	map_todigit(char const c)
{
	int	i;

	i = 0;
	while (g_lookup[i].alpha && tolower(c) != g_lookup[i].alpha)
		++i;
	if (g_lookup[i].alpha)
		return (g_lookup[i].digit);
	return (c);
}
