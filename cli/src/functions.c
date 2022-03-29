/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 01:22:24 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:24:41 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

static MYSQL *connect_db(void)
{
	MYSQL *sql_con;
	sql_con = mysql_init(NULL);
	if(mysql_real_connect(sql_con, DB_IP, "root", DB_PW, "42Labs", DB_PORT, NULL, 0) == NULL)
		printf("%s\n", mysql_error(sql_con));
	return (sql_con);
}

static void print_sql_error(MYSQL *sql_con)
{
	printf("%s\n", mysql_error(sql_con));
}

void show_help(void)
{
	printf("Usage: 42store_cli [OPTION]\n\n");
	printf("Show logs information.\n");
	printf("-a, --all\t\tshow all logs.\n");
	printf("-h, --help\t\tshow this help.\n");
	printf("-g, --grouped\t\tshow logs grouped by method and route.\n");
}

void show_grouped_logs(int tips)
{
	char query[2000];
	MYSQL *sql_con;

	sql_con = connect_db();
	sprintf(query, "SELECT COUNT(id) as total, `method`, route FROM logs GROUP BY `method`, route ORDER BY total Desc ");
	if (mysql_query(sql_con, query) == 0)
	{
		MYSQL_RES *result = mysql_store_result(sql_con);
		long unsigned int i = 0;
		MYSQL_ROW row;
		char obj[100];
		char *str;
		char *old_str;
		
		printf("Total\t\tMethod\t\tRoute\n");
		str = strdup("");
		while ((row = mysql_fetch_row(result)))
		{
			old_str = str;
			sprintf(obj,"%s\t\t%s\t\t%s\n", row[0], row[1], row[2]);
			str = ft_strjoin(old_str, obj);
			i++;
			ft_free_ptr((void *)&old_str);
		}
		mysql_free_result(result);
		printf("%s", str);
		free(str);
		if(tips)
			printf("For more options try 42store_cli -h.\n");
	}
	else
		print_sql_error(sql_con);
	mysql_close(sql_con);
}

void show_all_logs(void)
{
	char query[2000];
	MYSQL *sql_con;

	sql_con = connect_db();
	sprintf(query, "SElECT * FROM logs");
	if (mysql_query(sql_con, query) == 0)
	{
		MYSQL_RES *result = mysql_store_result(sql_con);
		long unsigned int i = 0;
		MYSQL_ROW row;
		char obj[100];
		char *str;
		char *old_str;
		
		printf("Id\t\tTimestramp\t\t\tMethod\t\tRoute\n");
		str = strdup("");
		while ((row = mysql_fetch_row(result)))
		{
			old_str = str;
			sprintf(obj,"%s\t\t%s\t\t%s\t\t%s\n", row[0], row[1], row[2], row[3]);
			str = ft_strjoin(old_str, obj);
			i++;
			ft_free_ptr((void *)&old_str);
		}
		mysql_free_result(result);
		printf("%s", str);
		free(str);
		
	}
	else
		print_sql_error(sql_con);
	mysql_close(sql_con);
}