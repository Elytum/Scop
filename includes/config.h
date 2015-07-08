/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** WINDOW SETTINGS
*/
# define SHOW_GPU 0
# define WIDTH 1800
# define HEIGHT 1200
# define WINDOW_NAME "scop"

/*
** PARSING SETTINGS
*/
# define MAX_VERTICES_PER_FACE 5
# define MAX_PARSING_LEN 20000000

# define TABLES_SIZE 100

/*
** AUTO-CALCULATED
*/
# define ASPECT (WIDTH / (float)HEIGHT)

#endif
