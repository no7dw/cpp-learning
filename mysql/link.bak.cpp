#include <stdlib.h>
#include <mysql/mysql.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(int arg, char **argv)
{
	char *user = "root", *pwd = "no7david", *dbname = "TestDB";
	MYSQL mysql;
	MYSQL_RES *mysql_ret;
	MYSQL_ROW mysql_row;
	unsigned long num_rows;
	int ret;
	mysql_init(&mysql);

	if(mysql_real_connect(&mysql, NULL,user, pwd, dbname, 0, NULL,0))
	{
		printf("Connection success!\n");
		ret = mysql_query(&mysql,"select * from TT");

		if(!ret)
		{
			printf("Query Sucess!\n");
			mysql_ret = mysql_store_result(&mysql);
			if(mysql_ret != NULL)
			{
				printf("Sotre Result Success!\n");
				num_rows = mysql_num_rows(mysql_ret);
				printf("rows = %d\n",(int) num_rows);
				int fieldcount = mysql_num_fields(mysql_ret);
				printf("fieldcount = %d\n", fieldcount);
				
				MYSQL_FIELD *field = NULL;
				if(num_rows != 0 )
				{
					for(int i =0;i <fieldcount; i++)
					{
						field = mysql_fetch_field_direct(mysql_ret, i);
						printf("%s\t",field->name);
					}
					printf("\n");
					while(mysql_row = mysql_fetch_row(mysql_ret))
					{
						printf("%s\t%s\t%s\n", mysql_row[0],mysql_row[1],mysql_row[2]);
					}
				}
				else
				{
					printf("mysql_num_rows Failed!\n");
					exit(-1);
				}	
			}
			else
			{
				printf("Store Failed!\n");
				exit(-1);
			}
			mysql_free_result(mysql_ret);
			mysql_close(&mysql);
			printf("mysql connection closed \n");
			exit(0);
		}
		else
		{
			printf("query Failed!\n");
			exit(-1);
		}
		mysql_close(&mysql);
		printf("mysql connection closed \n");
	}
	else
	{
		printf("connect error\n");
		exit(-1);
	}
	
}
