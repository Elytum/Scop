/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLES_H
# define TABLES_H

# include <config.h>
# include <sys/types.h>

typedef struct		s_tables
{
	size_t			tab[TABLES_SIZE];
	size_t			size;
	size_t			pos;
}					t_tables;

ssize_t				table_add(t_tables *tab, size_t md);

#endif
