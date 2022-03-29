/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_transaction_service.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 22:24:30 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 15:42:51 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void create_transaction_service(struct mg_connection *mg_con, double item_id, double item_quantity, char *type)
{
	char resp[10000];
	char query[2000];
	MYSQL *sql_con;

	sql_con = connect_db();
	if(item_id - (int)item_id == 0 && item_quantity - (int)item_quantity == 0)
	{
		sprintf(query, "SElECT id FROM items WHERE id = '%d'", (int)item_id);
		if (mysql_query(sql_con, query) == 0)
		{
			MYSQL_RES *result = mysql_store_result(sql_con);
			if (mysql_num_rows(result) > 0)
			{
				if(item_quantity > 0)
				{
						if (strcmp(type, "in") == 0 || strcmp(type, "out") == 0)
						{
							if(strcmp(type, "out") == 0)
								item_quantity *= -1;
							sprintf(query, "INSERT INTO transactions (item_id, item_quantity, type) VALUES (%f, %d, '%s')", item_id, (int)item_quantity, type);
							if (mysql_query(sql_con, query) == 0)
							{
								sprintf(query, "SElECT t.id, t.item_quantity, t.`type`, t.created_at, t.updated_at, t.item_id, i.name FROM transactions AS t INNER JOIN items AS i ON t.item_id = i.id ORDER BY id DESC LIMIT 1");
								if(mysql_query(sql_con, query) == 0)
								{
									MYSQL_RES *result = mysql_store_result(sql_con);
									MYSQL_ROW row;
									row = mysql_fetch_row(result);
									mjson_snprintf(resp, sizeof(resp), "{\"id\": \"%s\",\n\"item_quantity\": \"%s\",\n\"type\": \"%s\",\n\"created_at\": \"%s\",\n\"updated_at\": \"%s\",\n\"item\":{\n\"id\":\"%s\",\n\"name\":\"%s\"\n} }\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
									mg_http_reply(mg_con, 200, "Content-Type: application/json\r\n", "%s\n", resp);
									mysql_free_result(result);
								}
								else
									print_sql_error(mg_con, sql_con);
							}
							else
								print_sql_error(mg_con, sql_con);
						}
						else
						{
							printf("Invalid Type, only in and out are allowed.\n");
							mjson_snprintf(resp, sizeof(resp), "{\"message\": \"Invalid Type, only in and out are allowed.\"}");
							mg_http_reply(mg_con, 400, "Content-Type: application/json\r\n", "%s\n", resp);
						}
				}
				else
				{
					printf("Item quantity must be greater than 0.\n");
					mjson_snprintf(resp, sizeof(resp), "{\"message\": \"Item quantity must be greater than 0.\"}");
					mg_http_reply(mg_con, 400, "Content-Type: application/json\r\n", "%s\n", resp);
				}
			}
			else
			{
				printf("Item not found.\n");
				mjson_snprintf(resp, sizeof(resp), "{\"message\": \"Item not found.\"}");
				mg_http_reply(mg_con, 400, "Content-Type: application/json\r\n", "%s\n", resp);
			}
			mysql_free_result(result);
		}
		else
			print_sql_error(mg_con, sql_con);
	}
	else
	{
		printf("Invalid number, only intergers allowed.\n");
		mjson_snprintf(resp, sizeof(resp), "{\"message\": \"Invalid number, only intergers allowed.\"}");
		mg_http_reply(mg_con, 400, "Content-Type: application/json\r\n", "%s\n", resp);
	}
	mysql_close(sql_con);
	mysql_library_end();
}