/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:55:51 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/27 16:24:08 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cli.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		show_grouped_logs(1);
	else if (argc == 2)
	{
		if (strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--help") == 0)
			show_help();
		else if (strcmp(argv[1],"-a") == 0 || strcmp(argv[1],"--all") == 0)
			show_all_logs();
		else if (strcmp(argv[1],"-g") == 0 || strcmp(argv[1],"--grouped") == 0)
			show_grouped_logs(0);
		else
			printf("invalid option '%s'\nFor help try 42store_cli -h.\n", argv[1]);
	}
	else
		printf("For help try 42store_cli -h.\n");
	return (0);
}
