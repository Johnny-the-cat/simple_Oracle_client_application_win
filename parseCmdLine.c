#include <stdio.h>
#include <string.h>
#include <windows.h>

BOOL parseCmdLine(int argc, char* argv[], char *login, char *pass, char *dblink)
{
	const char *usage = "Usage: simple_Oracle_client_application login/pass@dbconnect";

	if (argc != 2)
	{
		printf("%s\n", usage);
		exit(EXIT_FAILURE);
	}

	char *slashpointer, *atpointer;
	int connectlinelen;

	connectlinelen = strlen(argv[1]);
	

	slashpointer = strchr(argv[1], '/');
	atpointer = strchr(argv[1], '@');
	if ((slashpointer - argv[1]) == 0 || *(argv[1]) == '/')
	{
		printf("Login is not found\n");
		printf("%s\n", usage);
		exit(EXIT_FAILURE);
	}

	if (slashpointer == NULL || (atpointer - slashpointer - 1) == 0)
	{
		printf("Pass is not found\n");
		printf("%s\n", usage);
		exit(EXIT_FAILURE);
	}

	if (atpointer == NULL || (connectlinelen - (atpointer - argv[1]) - 1) == 0)
	{
		printf("dblink is not found\n");
		printf("%s\n", usage);
		exit(EXIT_FAILURE);
	}

	if ((slashpointer - argv[1]) > 30)
	{
		printf("Login is too large\n");
		exit(EXIT_FAILURE);
	}

	if (atpointer - slashpointer - 1 > 30)
	{
		printf("Pass is too large\n");
		exit(EXIT_FAILURE);
	}

	if ((connectlinelen - (atpointer - argv[1]) - 1) > 127)
	{
		printf("dblink is too large\n");
		exit(EXIT_FAILURE);
	}

	strncpy_s(login, 32, argv[1], slashpointer - argv[1]);

	strncpy_s(pass, 32, slashpointer + 1, atpointer - slashpointer - 1);

	strncpy_s(dblink, 128, atpointer + 1, connectlinelen - (atpointer - argv[1]) - 1);

	
	return TRUE;
}