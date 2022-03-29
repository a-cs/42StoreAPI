/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_transactions_service.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:11:12 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 15:43:27 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void list_transactions_service(struct mg_connection *mg_con)
{
	char resp[10000];
	char query[2000];
	MYSQL *sql_con;

	sql_con = connect_db();
	sprintf(query, "SElECT t.id, t.item_quantity, t.`type`, t.created_at, t.updated_at, t.item_id, i.name FROM transactions AS t INNER JOIN items AS i ON t.item_id = i.id");
	if (mysql_query(sql_con, query) == 0)
	{
		MYSQL_RES *result = mysql_store_result(sql_con);
		long unsigned int i = 0;
		MYSQL_ROW row;
		char obj[200];
		char *json;
		char *old_json;
		
		json = strdup("");
		while ((row = mysql_fetch_row(result)))
		{
			old_json = json;
			if(i < (mysql_num_rows(result) - 1))
				sprintf(obj,"{\"id\": \"%s\",\n\"item_quantity\": \"%s\",\n\"type\": \"%s\",\n\"created_at\": \"%s\",\n\"updated_at\": \"%s\",\n\"item\":{\n\"id\":\"%s\",\n\"name\":\"%s\"\n} },\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
			else
				sprintf(obj,"{\"id\": \"%s\",\n\"item_quantity\": \"%s\",\n\"type\": \"%s\",\n\"created_at\": \"%s\",\n\"updated_at\": \"%s\",\n\"item\":{\n\"id\":\"%s\",\n\"name\":\"%s\"\n} }\n", row[0], row[1], row[2], row[3], row[4], row[5], row[6]);
			json = ft_strjoin(old_json, obj);
			i++;
			ft_free_ptr((void *)&old_json);
		}
		mysql_free_result(result);
		mjson_snprintf(resp, sizeof(resp), "[%s]", json);
		free(json);
		mg_http_reply(mg_con, 200, "Content-Type: application/json\r\n", "%s\n", resp);
	}
	else
		print_sql_error(mg_con, sql_con);
	mysql_close(sql_con);
	mysql_library_end();
}
