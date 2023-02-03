/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:50:01 by lhutt             #+#    #+#             */
/*   Updated: 2023/01/29 00:46:57 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

// https://stackoverflow.com/questions/31329952/

# define COLOR_RESET			"\x1B[0m"

# define COLOR_DANGER			"\x1B[38;5;196m"
# define COLOR_WARNING			"\x1B[38;5;226m"
# define COLOR_SUCCESS			"\x1B[38;5;190m"
# define COLOR_INFO				"\x1B[38;5;189m"
# define COLOR_ACCENT			"\x1B[38;5;117m"

# define COLOR_GREY_LIGHT		"\x1B[38;5;250m"
# define COLOR_GREY				"\x1B[38;5;245m"
# define COLOR_GREY_DARK		"\x1B[38;5;240m"

# define RLS					"\001"
# define RLE					"\002"

#endif
