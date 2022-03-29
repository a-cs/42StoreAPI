/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:53:27 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:42:14 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void root_route(struct mg_connection *mg_con, struct mg_http_message *req)
{
	struct mg_str method_get = mg_str("GET");
	char resp[10000];

	if(mg_strcmp(req->method, method_get) == 0)
	{
		mjson_snprintf(resp, sizeof(resp), "{\"endpoints\": \n[\"GET\t/\",\n\"GET\t/items\",\n\"POST\t/items\",\n\"GET\t/transactions\",\n\"POST\t/transactions\"\n]\n}");
		mg_http_reply(mg_con, 200, "Content-Type: application/json\r\n", "%s\n", resp);
	}
	else
	{
		printf("This method is not suported.\n");
		mjson_snprintf(resp, sizeof(resp), "{\"message\": \"This method is not suported.\"}");
		mg_http_reply(mg_con, 501, "Content-Type: application/json\r\n", "%s\n", resp);
	}
}
