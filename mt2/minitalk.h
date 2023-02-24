/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:39:04 by binanc            #+#    #+#             */
/*   Updated: 2023/01/22 16:35:39 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_itoa(int pid);

#endif