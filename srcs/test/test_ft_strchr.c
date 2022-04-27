/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 23:11:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/04/27 09:44:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_string.h"
#include "tester.h"
#include "e_ret.h"

typedef struct s_test	t_test;

struct s_test
{
	int const	num;
	char const	*str;
	char const	c;
};

static t_test const		g_test[] = {
{1,
	"",
	0},
{2,
	"",
	'A'},
{3,
	"chihuahua",
	'h'},
{4,
	"tirlarigo",
	'G'},
{5,
	"Une sacree tetrachiee",
	'r'},
{6,
	"Marvin",
	0},
{7,
	"\
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus erat eros, \
vestibulum eu egestas non, varius ut nulla. Fusce faucibus sit amet lorem at \
varius. Praesent sagittis eget velit et efficitur. Mauris euismod, mauris vel \
posuere dapibus, arcu neque accumsan lectus, ac venenatis velit nibh in magna. \
Ut dapibus feugiat odio, eu malesuada nunc bibendum a. Donec suscipit, felis a \
aliquet pharetra, neque augue imperdiet massa, non consectetur lorem risus ac \
lorem. Sed sagittis, mauris quis accumsan gravida, lorem lorem varius eros, \
nec venenatis arcu mauris nec massa. Nullam eget finibus urna. Phasellus \
varius congue neque, ut imperdiet lorem. In aliquet vitae est at volutpat. \
Ut dignissim arcu non nisi viverra, quis efficitur massa fringilla. Nunc \
accumsan est non augue mollis suscipit. Ut accumsan dui commodo, tempus purus \
eu, laoreet odio. Fusce scelerisque erat neque, eu vulputate risus aliquam \
efficitur. Proin et tellus diam. Nam vel enim consectetur, laoreet nunc sit \
amet, congue erat. Pellentesque hendrerit diam sed massa pharetra tincidunt. \
Sed finibus at tortor sit amet finibus. Integer consectetur lorem et eros \
tempus suscipit. Pellentesque gravida luctus tortor, ac ornare magna fringilla \
sit amet. Proin id commodo tortor, id fermentum diam. Interdum et malesuada \
fames ac ante ipsum primis in faucibus. Donec vehicula lorem sed justo tempus \
gravida. Nulla vulputate, erat vitae consectetur blandit, urna massa blandit \
est, et feugiat turpis nibh at neque. Donec sed suscipit orci. Donec id \
condimentum nunc. Nulla facilisi. Integer aliquam vehicula nibh sed lacinia. \
Vestibulum congue augue nec ex sollicitudin porttitor. Morbi placerat eleifend \
mi, nec tempus sem posuere nec. Nunc sit amet magna quis orci tincidunt \
aliquet. Sed quis odio ut ex euismod dignissim. Quisque eu ante auctor, \
scelerisque risus eget, faucibus ligula. Praesent at vestibulum dolor. \
Pellentesque non libero mauris. Cras facilisis sit amet massa et venenatis. \
Cras varius laoreet aliquam. Aliquam erat volutpat. Vestibulum libero sem \
dui. @",
	'@'},
{0}
};

int	test_ft_strchr(int *const ret)
{
	int	i;

	printf("%20s:", __func__ + 5);
	i = 0;
	while (g_test[i].num)
	{
		result(g_test[i].num,
			ft_strchr(g_test[i].str, g_test[i].c)
			== strchr(g_test[i].str, g_test[i].c));
		++i;
	}
	printf("\n");
	return (*ret = SUCCESS);
}
