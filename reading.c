/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woorikim <woorikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:53:16 by woorikim          #+#    #+#             */
/*   Updated: 2024/01/10 15:48:09 by woorikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

char	*read_input(void)
{
	char	*line;

	line = readline("minishell$ ");
	add_history(line);
	return (line);
}
