/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_routes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:53:27 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:12:09 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void items_routes(struct mg_connection *mg_con, struct mg_http_message *req)
{
	struct mg_str method_post = mg_str("POST");
	struct mg_str method_get = mg_str("GET");
	char resp[10000];
	char name[255];

	if(mg_strcmp(req->method, method_post) == 0)
	{
		if(mjson_get_string(req->body.ptr, req->body.len, "$.name", name, sizeof(name))!= -1)
			create_item_service(mg_con, name);
		else
			mg_http_reply(mg_con, 500, NULL, "%s", "Parameters missing");
	}
	else if(mg_strcmp(req->method, method_get) == 0)
	{
		list_items_service(mg_con);
	}
	else
	{
		printf("This method is not suported.\n");
		mjson_snprintf(resp, sizeof(resp), "{\"message\": \"This method is not suported.\"}");
		mg_http_reply(mg_con, 501, "Content-Type: application/json\r\n", "%s\n", resp);
	}
}
