/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: troudot <troudot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:25:56 by lucas             #+#    #+#             */
/*   Updated: 2023/03/31 11:44:24 by troudot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This code defines a function ft_match that takes two string parameters
 * str and exp, and returns a boolean value. The function checks
 * whether the string str matches the wildcard pattern exp. 
 * It uses a while loop to iterate through each character of the 
 * two strings, checking various conditions for matching. 
 * The function returns true if the strings match and false otherwise.
 * 
 * @param str the string to match
 * @param exp the expression to match
 * 
 * @return true if the string matches the expression.
 */
bool	ft_match(char *str, char *exp)
{
	if (!exp || !str)
		return (false);
	if (*str == '.' && *exp != '.')
		return (false);
	while (*str || *exp)
	{
		if (*exp == '*' && *str == 0)
			return (true);
		if (*str == *exp && (exp++, str++, true))
			;
		else if (*exp == '*' && *(exp + 1) == *str && *str == *(str + 1))
			str++;
		else if (*exp == '*' && *(exp + 1) && *(exp + 1) == '*')
			exp++;
		else if (*exp == '*' && *(exp + 1) != *str && *(str + 1))
			str++;
		else if (*exp == '*' && *(exp + 1) == *str)
			exp++;
		else if (*str && *exp == '*' && !*(exp + 1))
			return (true);
		else
			break ;
	}
	return (!*exp && !*str);
}
