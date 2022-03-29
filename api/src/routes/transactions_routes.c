/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transactions_routes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:11:03 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:12:32 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void transactions_routes(struct mg_connection *mg_con, struct mg_http_message *req)
{
	struct mg_str method_post = mg_str("POST");
	struct mg_str method_get = mg_str("GET");
	char resp[10000];

	if(mg_strcmp(req->method, method_post) == 0)
	{
		double item_id, item_quantity;
		char type[4];
		if(mjson_get_number(req->body.ptr, req->body.len, "$.item_id", &item_id) != 0 
		&& mjson_get_number(req->body.ptr, req->body.len, "$.item_quantity", &item_quantity) != 0
		&& mjson_get_string(req->body.ptr, req->body.len, "$.type", type, sizeof(type))!= -1)
		{
			create_transaction_service(mg_con, item_id, item_quantity, type);
			
		}
		else
			mg_http_reply(mg_con, 500, NULL, "%s", "Parameters missing");
	}
	else if(mg_strcmp(req->method, method_get) == 0)
	{
		list_transactions_service(mg_con);
	}
	else
	{
		printf("This method is not suported.\n");
		mjson_snprintf(resp, sizeof(resp), "{\"message\": \"This method is not suported.\"}");
		mg_http_reply(mg_con, 501, "Content-Type: application/json\r\n", "%s\n", resp);
	}
}
