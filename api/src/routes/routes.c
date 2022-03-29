/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:17:37 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:29:37 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/api.h"

void routes(struct mg_connection *mg_con, struct mg_http_message *req)
{
	print_routes_log(mg_con, req);
	if (mg_http_match_uri(req, "/"))
		root_route(mg_con, req);
	else if (mg_http_match_uri(req, "/items"))
		items_routes(mg_con, req);
	else if (mg_http_match_uri(req, "/transactions"))
		transactions_routes(mg_con, req);
	else 
		mg_http_reply(mg_con, 500, NULL, "%s", "Invalid URI");
}