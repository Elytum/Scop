/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   models.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <config.h>
#include <tables.h>
#include <stdlib.h>
#include <string.h>

ssize_t		table_add(t_tables *tab, size_t md)
{
	ssize_t	position;

	position = 0;
	while (tab->tab[position] != 0 && position < TABLES_SIZE)
		position++;
	if (position == TABLES_SIZE)
		return (-1);
	tab->tab[position] = md;
	return (position);
}
