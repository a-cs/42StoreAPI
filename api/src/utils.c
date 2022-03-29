/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:51:15 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:20:40 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

MYSQL *connect_db(void)
{
	MYSQL *sql_con;
	sql_con = mysql_init(NULL);
	if(mysql_real_connect(sql_con, DB_IP, "root", DB_PW, "42Labs", DB_PORT, NULL, 0) == NULL)
		printf("%s\n", mysql_error(sql_con));
	return (sql_con);
}

void print_sql_error(struct mg_connection *mg_con, MYSQL *sql_con)
{
	char resp[10000];
	printf("%s\n", mysql_error(sql_con));
	mjson_snprintf(resp, sizeof(resp), "{%Q: \"%s\"\n}", "Sql error", mysql_error(sql_con));
	mg_http_reply(mg_con, 503, "Content-Type: application/json\r\n", "%s\n", resp);
}

void print_routes_log(struct mg_connection *mg_con, struct mg_http_message *req)
{
	MYSQL *sql_con;
	char query[2000];

	sql_con = connect_db();
	sprintf(query, "INSERT INTO logs (`method`, route, request) VALUES ('%.*s', '%.*s', '%s')", (int)req->method.len,req->method.ptr, (int)req->uri.len, req->uri.ptr, req->method.ptr);
	if (mysql_query(sql_con, query) != 0)
		print_sql_error(mg_con, sql_con);
	mysql_close(sql_con);
}