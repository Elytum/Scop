/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_os.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V_OS_H
# define V_OS_H

# include <stdlib.h>
# include <OpenGL/gl3.h>

typedef	struct		s_vs
{
	GLuint			id;
	struct s_vs		*past;
}					t_vs;

void				vs_add(t_vs **ptr, int id);
void				destroy_v_os(void);

t_vs	*g_vaos;
t_vs	*g_vbos;
#endif
