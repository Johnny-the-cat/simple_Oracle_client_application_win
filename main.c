#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include "OraFunctions.h"

//������� ��� �������� ������ ������� ����������, ���������, �����, ������ � ������ �������� � ����
BOOL parseCmdLine(int argc, char* argv[], char *login, char *pass, char *dblink);

int main(int argc, char* argv[])
{
	//����� ��� �����������. �������� �� ���������� ��������� ������. 
	char login[32] = { 0 };
	//������ ��� �����������. �������� �� ���������� ��������� ������. 
	char pass[32] = { 0 };
	//������ ����������� � ���� ������.
	char dbconnect[128] = { 0 };
	
	//�������� ����������� ������ �� ���������� ��������� ������
	parseCmdLine(argc, argv, login, pass, dbconnect);


	//����� ������������ ���������� OCI.dll. �� ���������� ������ ����� ����������, ������ FreeLibrary(hOCIDll)
	HMODULE hOCIDll = NULL;
	//��������� ��������� (Oracle Environment) ���������������� �������� InitOraEnvironment. ������������ �������� CloseOraEnvironment
	OCIEnv *hOraEnv = NULL;
	//��������� ��� ��������� � ������ ������ ������ ������� OCI.dll.���������������� �������� InitOraEnvironment. ������������ �������� CloseOraEnvironment
	OCIError *hOraErr = NULL;


	//��������� OCIServer ��� �������� ������. ������ ����������� ������� ������� CloseSession
	OCIServer *hOraServer = NULL;
	//��������� OCISvcCtx ��� �������� ������. ������ ����������� ������� ������� CloseSession
	OCISvcCtx *hOraSvcCtx = NULL;
	//��������� OCISession ��� �������� ������. ������ ����������� ������� ������� CloseSession
	OCISession *hOraSession = NULL;

	printf("���������� ���������� oci.dll\n");
	hOCIDll = LoadLibraryW(L"oci.dll");
	if (hOCIDll == NULL)
	{
		printf("�� ���� ��������� oci.dll. ���������, ��� Oracle Client ����������� ����������� ���������� � �������� � ���������� ��������� PATH\n");
		exit(EXIT_FAILURE);
	}

	printf("��������� oci �������\n");
	if (!LoadOciFunctions(hOCIDll))
	{
		printf("�� ������� ��������� ��� ����������� OCI �������. ��������� ������ oci.dll � ������� �������� ��������� � ���������� PATH\n");
		FreeLibrary(hOCIDll);
		exit(EXIT_FAILURE);
	}

	printf("�������������� ���������\n");
	if (!InitOraEnvironment(&hOraEnv, &hOraErr))
	{
		printf("�� ���������� ���������������� OCI ���������, ���������� ����� �������\n");
		FreeLibrary(hOCIDll);
		return EXIT_FAILURE;
	}

	//����� ������, ������� ����� ��������� � �������� ��������. ���������� � "SYS" ������������, ����� �� ���� OCI_SYSDBA
	char tmpLogin[32] = { 0 };
	strcpy(tmpLogin, login);
	_strupr(tmpLogin);

	printf("������������ � ����\n");
	if (!CreateSession(hOraEnv, hOraErr, &hOraServer, &hOraSvcCtx, &hOraSession, login, pass, dbconnect, !strcmp("SYS", tmpLogin)))
	{
		printf("�� ���������� ������������ � ����. ����������� ������� � ��������� ������ ����������\n");

		CloseOraEnvironment(hOraEnv, hOraErr);
		FreeLibrary(hOCIDll);

		return EXIT_FAILURE;
	}

	char *create_table_statement = "CREATE TABLE simple_table (id NUMBER, textfield VARCHAR(100)) ";
	printf("������� �������� �������\n");
	ExecuteStatement(hOraSvcCtx, hOraEnv, hOraErr, create_table_statement);

	printf("��������� ������ � �������\n");
	InsertDataInTable(hOraSvcCtx, hOraEnv, hOraErr);

	printf("�������� ������ �� �������\n");
	SelectDataFromTable(hOraSvcCtx, hOraEnv, hOraErr);

	printf("������� �� ����� �������\n");
	ExecuteStatement(hOraSvcCtx, hOraEnv, hOraErr, "drop table simple_table");

	printf("����������� � ��������� ������ ����������\n");
	CloseSession(hOraErr, hOraServer, hOraSvcCtx, hOraSession);
	CloseOraEnvironment(hOraEnv, hOraErr);
	FreeLibrary(hOCIDll);
	return EXIT_FAILURE;

}