/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_item_service.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:08:29 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 15:42:45 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void create_item_service(struct mg_connection *mg_con, char *name)
{
	char resp[10000];
	char query[2000];
	int total_stock = 0;
	MYSQL *sql_con;

	sql_con = connect_db();
	sprintf(query, "SElECT id FROM items WHERE name = '%s'", name);
	if (mysql_query(sql_con, query) == 0)
	{
		MYSQL_RES *result = mysql_store_result(sql_con);
		if (mysql_num_rows(result) == 0)
		{
			sprintf(query, "INSERT INTO items (name, total_stock) VALUES ('%s', '%d')", name, total_stock);
			if (mysql_query(sql_con, query) == 0)
			{
				sprintf(query, "SElECT * FROM items ORDER BY id DESC LIMIT 1");
				if(mysql_query(sql_con, query) == 0)
				{
					MYSQL_RES *result2 = mysql_store_result(sql_con);
					MYSQL_ROW row;
					row = mysql_fetch_row(result2);
					mjson_snprintf(resp, sizeof(resp), "{\"id\": \"%s\",\n\"name\": \"%s\",\n\"total_stock\": \"%s\",\n\"created_at\": \"%s\",\n\"updated_at\": \"%s\"}\n", row[0], row[1], row[2], row[3], row[4]);
					mg_http_reply(mg_con, 200, "Content-Type: application/json\r\n", "%s\n", resp);
					mysql_free_result(result2);
				}
				else
					print_sql_error(mg_con, sql_con);
			}
			else
				print_sql_error(mg_con, sql_con);
		}
		else
		{
			printf("Item name already in use\n");
			mjson_snprintf(resp, sizeof(resp), "{\"message\": \"Item name already in use.\"}");
			mg_http_reply(mg_con, 400, "Content-Type: application/json\r\n", "%s\n", resp);
		}
		mysql_free_result(result);
	}
	else
		print_sql_error(mg_con, sql_con);
	mysql_close(sql_con);
	mysql_library_end();
}
