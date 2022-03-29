/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:03:41 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:14:10 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/api.h"

int	terminate;

void handle_signal(int signal)
{
	terminate = signal;
}


static void fn(struct mg_connection *mg_con, int ev, void *ev_data, void *fn_data)
{
	if (fn_data)
	{
	
	}
	if (ev == MG_EV_HTTP_MSG) {
		struct mg_http_message *req = (struct mg_http_message *) ev_data;
		routes(mg_con, req);
	}
}


int main(void) {
	struct mg_mgr mgr;

	signal(SIGINT, handle_signal);
	mg_mgr_init(&mgr);
	mg_http_listen(&mgr, "http://localhost:8000", fn, &mgr);
	printf("Servidor iniciado em: http://localhost:8000\n");
	while (terminate == 0)
		mg_mgr_poll(&mgr, 1000);
	mg_mgr_free(&mgr);
	return 0;
}