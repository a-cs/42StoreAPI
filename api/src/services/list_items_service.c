/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_items_service.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:22:13 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 15:43:12 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void list_items_service(struct mg_connection *mg_con)
{
	char resp[10000];
	char query[2000];
	MYSQL *sql_con;

	sql_con = connect_db();
	sprintf(query, "SElECT * FROM items");
	if (mysql_query(sql_con, query) == 0)
	{
		MYSQL_RES *result = mysql_store_result(sql_con);
		long unsigned int i = 0;
		MYSQL_ROW row;
		char obj[100];
		char *json;
		char *old_json;
		
		json = strdup("");
		while ((row = mysql_fetch_row(result)))
		{
			old_json = json;
			if(i < (mysql_num_rows(result) - 1))
				sprintf(obj,"{\"id\": \"%s\",\n\"name\": \"%s\",\n\"total_stock\": \"%s\",\n\"created_at\": \"%s\",\n\"updated_at\": \"%s\"},\n", row[0], row[1], row[2], row[3], row[4]);
			else
				sprintf(obj,"{\"id\": \"%s\",\n\"name\": \"%s\",\n\"total_stock\": \"%s\",\n\"created_at\": \"%s\",\n\"updated_at\": \"%s\"}\n", row[0], row[1], row[2], row[3], row[4]);
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
