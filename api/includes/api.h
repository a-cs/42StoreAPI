/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:45:23 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:30:19 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

#include <stdio.h>
#include "../libs/mongoose.h"
#include "../libs/mjson.h"
#include "../libs/libft/libft.h"
#include <mysql/mysql.h>
#include <string.h>
#include<signal.h>

#define DB_PW "sqlpw"
#define DB_IP "127.0.0.1"
#define DB_PORT 3306

void routes(struct mg_connection *mg_con, struct mg_http_message *req);
MYSQL *connect_db(void);
void print_sql_error(struct mg_connection *mg_con, MYSQL *sql_con);
void items_routes(struct mg_connection *mg_con, struct mg_http_message *req);
void create_item_service(struct mg_connection *mg_con, char *name);
void list_items_service(struct mg_connection *mg_con);
void transactions_routes(struct mg_connection *mg_con, struct mg_http_message *req);
void list_transactions_service(struct mg_connection *mg_con);
void create_transaction_service(struct mg_connection *mg_con, double item_id, double item_quantity, char *type);
void root_route(struct mg_connection *mg_con, struct mg_http_message *req);
void print_routes_log(struct mg_connection *mg_con, struct mg_http_message *req);


#endif