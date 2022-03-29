/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:59:10 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:20:07 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

#include <stdio.h>
#include "../../api/libs/libft/libft.h"
#include <mysql/mysql.h>
#include <string.h>

#define DB_PW "sqlpw"
#define DB_IP "127.0.0.1"
#define DB_PORT 3306

void show_help(void);
void show_grouped_logs(int tips);
void show_all_logs(void);

#endif