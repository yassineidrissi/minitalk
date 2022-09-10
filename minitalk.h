/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student1337.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:50:30 by yaidriss          #+#    #+#             */
/*   Updated: 2022/09/10 00:55:15 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINITALK_H

# define MINITALK_H


# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include <ctype.h>
# include "libft/libft.h"

int	ft_printf(const char *format, ...);

#endif