#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include "oci.h"
#include "oratypes.h"
#include "orl.h"
#include "ocipfndfn.h"
#include "OraFunctions.h"
#include <strsafe.h>



#define CONSOLE_ERROR_OUTPUT
//#define MESSAGEBOX_ERROR_OUTPUT

pOCIEnvCreate OCIEnvCreate;

pOCIEnvNlsCreate OCIEnvNlsCreate;

pOCITerminate OCITerminate;

pOCIHandleAlloc OCIHandleAlloc;

pOCIServerAttach OCIServerAttach;

pOCIAttrSet OCIAttrSet;

pOCISessionBegin OCISessionBegin;

pOCISessionEnd OCISessionEnd;

pOCIStmtPrepare OCIStmtPrepare;

pOCIDefineByPos OCIDefineByPos;

pOCIStmtExecute OCIStmtExecute;

pOCIBindByName OCIBindByName;

pOCIBindByPos OCIBindByPos;

pOCITransCommit OCITransCommit;

pOCIHandleFree OCIHandleFree;

pOCIServerDetach OCIServerDetach;

pOCIStmtFetch2 OCIStmtFetch2;

pOCIErrorGet OCIErrorGet;

pOCIRawAllocSize OCIRawAllocSize;

pOCIRawAssignBytes OCIRawAssignBytes;

pOCILobFileSetName OCILobFileSetName;

pOCIDescriptorAlloc OCIDescriptorAlloc;

pOCIDescriptorFree OCIDescriptorFree;

pOCILobFileOpen OCILobFileOpen;

pOCILobFileClose OCILobFileClose;

pOCILobGetLength2 OCILobGetLength2;

pOCILobRead2 OCILobRead2;

pOCILobFileExists OCILobFileExists;


BOOL LoadOciFunctions(HMODULE hOCIDll)
{

	OCIEnvCreate = (pOCIEnvCreate)GetProcAddress(hOCIDll,
		"OCIEnvCreate");
	if (OCIEnvCreate == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIEnvCreate", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIEnvCreate\n");
#endif
		return FALSE;
	}
	

	OCIEnvNlsCreate = (pOCIEnvNlsCreate)GetProcAddress(hOCIDll,
		"OCIEnvNlsCreate");
	if (OCIEnvNlsCreate == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIEnvNlsCreate", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIEnvNlsCreate\n");
#endif
		return FALSE;
	}
	

	OCITerminate = (pOCITerminate)GetProcAddress(hOCIDll,
		"OCITerminate");
	if (OCITerminate == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCITerminate", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCITerminate\n");
#endif		
		return FALSE;
	}
	

	OCIHandleAlloc = (pOCIHandleAlloc)GetProcAddress(hOCIDll,
		"OCIHandleAlloc");
	if (OCIHandleAlloc == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIHandleAlloc", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIHandleAlloc\n");
#endif
		return FALSE;
	}
	

	OCIServerAttach = (pOCIServerAttach)GetProcAddress(hOCIDll,
		"OCIServerAttach");
	if (OCIServerAttach == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIServerAttach", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIServerAttach\n");
#endif
		return FALSE;
	}
	
	OCIAttrSet = (pOCIAttrSet)GetProcAddress(hOCIDll,
		"OCIAttrSet");
	if (OCIAttrSet == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIAttrSet", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIAttrSet\n");
#endif
		return FALSE;
	}
	
	OCISessionBegin = (pOCISessionBegin)GetProcAddress(hOCIDll,
		"OCISessionBegin");
	if (OCISessionBegin == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCISessionBegin", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCISessionBegin\n");
#endif
		return FALSE;
	}
	

	OCISessionEnd = (pOCISessionEnd)GetProcAddress(hOCIDll,
		"OCISessionEnd");
	if (OCISessionEnd == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCISessionEnd", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCISessionEnd\n");
#endif
		return FALSE;
	}
	

	OCIStmtPrepare = (pOCIStmtPrepare)GetProcAddress(hOCIDll,
		"OCIStmtPrepare");
	if (OCIStmtPrepare == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIStmtPrepare", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIStmtPrepare\n");
#endif
		return FALSE;
	}
	
	OCIDefineByPos = (pOCIDefineByPos)GetProcAddress(hOCIDll,
		"OCIDefineByPos");
	if (OCIDefineByPos == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIDefineByPos", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIDefineByPos\n");
#endif
		return FALSE;
	}
	
	OCIStmtExecute = (pOCIStmtExecute)GetProcAddress(hOCIDll,
		"OCIStmtExecute");
	if (OCIStmtExecute == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIStmtExecute", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIStmtExecute\n");
#endif
		return FALSE;
	}
	
	OCIBindByName = (pOCIBindByName)GetProcAddress(hOCIDll,
		"OCIBindByName");
	if (OCIBindByName == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIBindByName", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIBindByName\n");
#endif
		return FALSE;
	}
	
	OCIBindByPos = (pOCIBindByPos)GetProcAddress(hOCIDll,
		"OCIBindByPos");
	if (OCIBindByPos == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIBindByPos", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIBindByPos\n");
#endif
		return FALSE;
	}
	
	OCITransCommit = (pOCITransCommit)GetProcAddress(hOCIDll,
		"OCITransCommit");
	if (OCITransCommit == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCITransCommit", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCITransCommit\n");
#endif
		return FALSE;
	}
	
	OCIHandleFree = (pOCIHandleFree)GetProcAddress(hOCIDll,
		"OCIHandleFree");
	if (OCIHandleFree == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIHandleFree", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIHandleFree\n");
#endif
		return FALSE;
	}
	
	OCIServerDetach = (pOCIServerDetach)GetProcAddress(hOCIDll,
		"OCIServerDetach");
	if (OCIServerDetach == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIServerDetach", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIServerDetach\n");
#endif
		return FALSE;
	}
	
	OCIStmtFetch2 = (pOCIStmtFetch2)GetProcAddress(hOCIDll,
		"OCIStmtFetch2");
	if (OCIStmtFetch2 == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIStmtFetch2", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIStmtFetch2\n");
#endif
		return FALSE;
	}
	
	OCIErrorGet = (pOCIErrorGet)GetProcAddress(hOCIDll,
		"OCIErrorGet");
	if (OCIErrorGet == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIErrorGet", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIErrorGet\n");
#endif
		return FALSE;
	}
	
	OCIRawAllocSize = (pOCIRawAllocSize)GetProcAddress(hOCIDll,
		"OCIRawAllocSize");
	if (OCIRawAllocSize == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIRawAllocSize", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIRawAllocSize\n");
#endif
		return FALSE;
	}
	
	OCIRawAssignBytes = (pOCIRawAssignBytes)GetProcAddress(hOCIDll,
		"OCIRawAssignBytes");
	if (OCIRawAssignBytes == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIRawAssignBytes", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIRawAssignBytes\n");
#endif
		return FALSE;
	}
	
	OCILobFileSetName = (pOCILobFileSetName)GetProcAddress(hOCIDll,
		"OCILobFileSetName");
	if (OCILobFileSetName == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCILobFileSetName", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCILobFileSetName\n");
#endif
		return FALSE;
	}
	
	OCIDescriptorAlloc = (pOCIDescriptorAlloc)GetProcAddress(hOCIDll,
		"OCIDescriptorAlloc");
	if (OCIDescriptorAlloc == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIDescriptorAlloc", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIDescriptorAlloc\n");
#endif
		return FALSE;
	}
	
	OCIDescriptorFree = (pOCIDescriptorFree)GetProcAddress(hOCIDll,
		"OCIDescriptorFree");
	if (OCIDescriptorFree == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCIDescriptorFree", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCIDescriptorFree\n");
#endif
		return FALSE;
	}
	
	OCILobFileOpen = (pOCILobFileOpen)GetProcAddress(hOCIDll,
		"OCILobFileOpen");
	if (OCILobFileOpen == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCILobFileOpen", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCILobFileOpen\n");
#endif
		return FALSE;
	}
	
	OCILobFileClose = (pOCILobFileClose)GetProcAddress(hOCIDll,
		"OCILobFileClose");
	if (OCILobFileClose == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCILobFileClose", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCILobFileClose\n");
#endif
		return FALSE;
	}
	
	OCILobGetLength2 = (pOCILobGetLength2)GetProcAddress(hOCIDll,
		"OCILobGetLength2");
	if (OCILobGetLength2 == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCILobGetLength2", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCILobGetLength2\n");
#endif
		return FALSE;
	}
	
	OCILobRead2 = (pOCILobRead2)GetProcAddress(hOCIDll,
		"OCILobRead2");
	if (OCILobRead2 == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCILobRead2", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCILobRead2\n");
#endif
		return FALSE;
	}
	
	OCILobFileExists = (pOCILobFileExists)GetProcAddress(hOCIDll,
		"OCILobFileExists");
	if (OCILobFileExists == NULL) {
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"LoadOciFunctions: can't load OCILobFileExists", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("LoadOciFunctions: can't load OCILobFileExists\n");
#endif
		return FALSE;
	}
	
	return TRUE;
}

void checkerr(OCIError *errhp, sword status)
{
	text errbuf[512];
	WCHAR wchar_errbuf[512];
	sb4 errcode = 0;

	switch (status)
	{
	case OCI_SUCCESS:
		//(void)printf("OCI_SUCCESS\n");
		break;

	case OCI_SUCCESS_WITH_INFO:
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Error - OCI_SUCCESS_WITH_INFO", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - OCI_SUCCESS_WITH_INFO\n");
#endif
		break;

	case OCI_NEED_DATA:
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Error - OCI_NEED_DATA", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - OCI_NEED_DATA\n");
#endif
		break;

	case OCI_NO_DATA:
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Error - OCI_NODATA", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - OCI_NODATA\n");
#endif
		break;

	case OCI_ERROR:
		(void)OCIErrorGet((dvoid *)errhp, (ub4)1, (text *)NULL, &errcode,
			errbuf, (ub4) sizeof(errbuf), OCI_HTYPE_ERROR);
		MultiByteToWideChar(CP_UTF8, 0, (char *)errbuf, 512, wchar_errbuf, 512);
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, wchar_errbuf, L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - %.*s\n", 512, errbuf);
#endif
		break;

	case OCI_INVALID_HANDLE:
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Error - OCI_INVALID_HANDLE", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - OCI_INVALID_HANDLE\n");
#endif
		break;

	case OCI_STILL_EXECUTING:
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Error - OCI_STILL_EXECUTE", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - OCI_STILL_EXECUTE\n");
#endif
		break;

	case OCI_CONTINUE:
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Error - OCI_CONTINUE", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		(void)printf("Error - OCI_CONTINUE\n");
#endif
		break;

	default:
		break;
	}
}


/*Функция инициализирует окружение OCIEnv и OCIError*/
BOOL InitOraEnvironment(OCIEnv **hOraEnv, OCIError **hOraErr)
{
	OCIEnv *localHandleOraEnv = NULL;
	OCIError *localHanleOraErr = NULL;

	
	if (OCIEnvCreate((OCIEnv **)&localHandleOraEnv,
		(ub4)OCI_DEFAULT | OCI_OBJECT,
		(const void  *)0,
		(const void  * (*)(void  *, size_t))0,
		(const void  * (*)(void  *, void  *, size_t))0,
		(const void(*)(void  *, void  *))0,
		(size_t)0, (void  **)0))

	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InitOraEnvironment function - can not create OCI Environment handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InitOraEnvironment function - can not create OCI Environment handle\n");
#endif
		return FALSE;
	}
	
	localHanleOraErr = NULL;
	if (OCIHandleAlloc((const void *)localHandleOraEnv,
		(void **)&localHanleOraErr,
		OCI_HTYPE_ERROR,
		(size_t)0,
		(void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InitOraEnvironment function - can not allocate OCI Error handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InitOraEnvironment function - can not allocate OCI Error handle\n");
#endif
		return FALSE;
	}
	
	*hOraEnv = localHandleOraEnv;
	*hOraErr = localHanleOraErr;

	return TRUE;

}

void CloseOraEnvironment(OCIEnv *hOraEnv, OCIError *hOraErr)
{
	if (OCIHandleFree(hOraErr, OCI_HTYPE_ERROR))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseOraEnvironment function - can not free OCI Error handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseOraEnvironment function - can not free OCI Error handle\n");
#endif
	}

	if (OCIHandleFree(hOraEnv, OCI_HTYPE_ENV))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseOraEnvironment function - can not free OCI Env handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseOraEnvironment function - can not free OCI Env handle\n");
#endif
	}

	OCITerminate(OCI_DEFAULT);
}


BOOL CreateSession(OCIEnv *hOraEnv, OCIError *hOraErr, OCIServer **hOraServer, OCISvcCtx **hOraSvcCtx, OCISession **hOraSession, char *usernameutf8, char *passwordutf8, char *dbnameutf8, BOOL assysdba)
{
	OCIServer *localHandleOraServer;
	OCISvcCtx *localHandleOraSvcCtx;
	OCISession *localHandleSession;


	localHandleOraServer = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&localHandleOraServer,
		OCI_HTYPE_SERVER,
		(size_t)0,
		(dvoid **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - can not allocate server handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - can not allocate server handle\n");
#endif
		return FALSE;
	}
	
	if (OCIServerAttach(localHandleOraServer, hOraErr, (const OraText *)dbnameutf8, (sb4)strlen(dbnameutf8), (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Не могу подключиться к серверу БД. Проверьте TNS или строку подключения. Возможно, ошибка сети", L"Ошибка", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Unable to attach to server. Check TNS name or connect string. May be network error\n");
#endif
		return FALSE;
	}

	localHandleOraSvcCtx = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv,
		(void **)&localHandleOraSvcCtx,
		OCI_HTYPE_SVCCTX,
		(size_t)0,
		(dvoid **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - can not allocate service handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - can not allocate service handle\n");
#endif
		return FALSE;
	}
	
	if (OCIAttrSet((void *)localHandleOraSvcCtx, OCI_HTYPE_SVCCTX, (void *)localHandleOraServer, (ub4)0, OCI_ATTR_SERVER, (OCIError *)hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to put server handle to service context", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to put server handle to service context for\n");
#endif
		return FALSE;
	}
	
	localHandleSession = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&localHandleSession, (ub4)OCI_HTYPE_SESSION, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - can not allocate session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - can not allocate session handle\n");
#endif
		return FALSE;
	}
	

	if (OCIAttrSet((void *)localHandleSession, (ub4)OCI_HTYPE_SESSION, (void *)usernameutf8, (ub4)strlen(usernameutf8), (ub4)OCI_ATTR_USERNAME, hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to set username to session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to set username to session handle\n");
#endif
		return FALSE;
	}

	
	if (OCIAttrSet((void *)localHandleSession, (ub4)OCI_HTYPE_SESSION, (void *)passwordutf8, (ub4)strlen(passwordutf8), (ub4)OCI_ATTR_PASSWORD, hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to set password to session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to set password to session handle\n");
#endif
		return FALSE;
	}

	
	if (OCISessionBegin(localHandleOraSvcCtx, hOraErr, localHandleSession, OCI_CRED_RDBMS, (ub4)(OCI_DEFAULT | (assysdba ? OCI_SYSDBA : 0))) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Не получается установить рабочую сессию. Проверьте правильность пользователя и пароля", L"Ошибка", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Unable to begin session. Check your login and password is correct\n");
#endif
		return FALSE;
	}

	if (OCIAttrSet((void *)localHandleOraSvcCtx, (ub4)OCI_HTYPE_SVCCTX, (void *)localHandleSession, (ub4)0, (ub4)OCI_ATTR_SESSION, hOraErr) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CreateSession function - unable to set session handle into the service context handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CreateSession function - unable to set session handle into the service context handle.\n");
#endif
		return FALSE;
	}

	*hOraServer = localHandleOraServer;
	*hOraSvcCtx = localHandleOraSvcCtx;
	*hOraSession = localHandleSession;

	return TRUE;
}

void CloseSession(OCIError *hOraErr, OCIServer *hOraServer, OCISvcCtx *hOraSvcCtx, OCISession *hOraSession)
{
	if (OCISessionEnd(hOraSvcCtx, hOraErr, hOraSession, OCI_DEFAULT))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to end session", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to end session.\n");
#endif
	}

	if (OCIHandleFree(hOraSession, OCI_HTYPE_SESSION))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to free session handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to free session handle\n");
#endif
	}

	if (OCIHandleFree(hOraSvcCtx, OCI_HTYPE_SVCCTX))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to free service context handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to free service context handle\n");
#endif
	}

	if (OCIServerDetach(hOraServer, hOraErr, (ub4)OCI_DEFAULT))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to detach server", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to detach server\n");
#endif
	}

	if (OCIHandleFree(hOraServer, OCI_HTYPE_SERVER))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, CloseSession function - unable to free server handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, CloseSession function - unable to free server handle\n");
#endif
	}
}

BOOL ExecuteStatement(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr, char *statement)
{
	sword status;

	OCIStmt *hOraPlsqlStatement = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, ExecuteStatement function - can not allocate hOraPlsqlStatement handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, ExecuteStatement function - can not allocate hOraPlsqlStatement handle\n");
#endif
		return FALSE;
	}
	
	if (OCIStmtPrepare(hOraPlsqlStatement, hOraErr, (const OraText *)statement, (ub4)strlen(statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, ExecuteStatement function - unable to prepare statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, ExecuteStatement function - unable to prepare statement\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	status = OCIStmtExecute(hOraSvcCtx, hOraPlsqlStatement, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, ExecuteStatement function - unable to execute plsql statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, ExecuteStatement function - unable to execute plsql statement\n");
#endif
		checkerr(hOraErr, status);
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
	return TRUE;
}

BOOL InsertDataInTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr)
{
	char * insert_statement = "INSERT INTO simple_table\
	(id, textfield)\
	VALUES\
	(:id, :string)";

	sword status;

	int id;
	char stringBuffer[100];

	OCIStmt *hOraPlsqlStatement = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InsertDataInTable function - can not allocate hOraPlsqlStatement handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InsertDataInTable function - can not allocate hOraPlsqlStatement handle\n");
#endif
		return FALSE;
	}

	if (OCIStmtPrepare(hOraPlsqlStatement, hOraErr, (const OraText *)insert_statement, (ub4)strlen(insert_statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, InsertDataInTable function - unable to prepare statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, InsertDataInTable function - unable to prepare statement\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIBind  *bnd1p = NULL;
	OCIBind  *bnd2p = NULL;
	OCIBindByName(hOraPlsqlStatement, &bnd1p, hOraErr, (text *)":id", -1, (void *)&id, (sb4)sizeof(id), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);
	OCIBindByName(hOraPlsqlStatement, &bnd2p, hOraErr, (text *)":string", -1, (void *)stringBuffer, (sb4)(sizeof(stringBuffer)), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, (ub4)0, (ub4 *)0, OCI_DEFAULT);
	
	for (id = 1; id < 10; id++)
	{
		sprintf(stringBuffer, "This is the %d string", id);
		
		status = OCIStmtExecute(hOraSvcCtx, hOraPlsqlStatement, hOraErr, (ub4)1, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
		if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
		{
			checkerr(hOraErr, status);
			OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
			return FALSE;
		}
	}


	OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);

	return TRUE;
}

BOOL SelectDataFromTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr)
{
	char * select_statement = "select id, textfield from simple_table order by id";

	sword status;

	int id;
	char stringBuffer[100];

	OCIStmt *hOraPlsqlStatement = NULL;
	if (OCIHandleAlloc((const void *)hOraEnv, (void **)&hOraPlsqlStatement, OCI_HTYPE_STMT, (size_t)0, (void **)0))
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - can not allocate hOraPlsqlStatement handle", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - can not allocate hOraPlsqlStatement handle\n");
#endif
		return FALSE;
	}

	if (OCIStmtPrepare(hOraPlsqlStatement, hOraErr, (const OraText *)select_statement, (ub4)strlen(select_statement), (ub4)OCI_NTV_SYNTAX, (ub4)OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to prepare statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to prepare statement\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraIdDefine = NULL;
	if (OCIDefineByPos(hOraPlsqlStatement, &OraIdDefine, hOraErr, 1, (void *)&id, (sword)sizeof(id), SQLT_INT, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to DefineByPos", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to DefineByPos\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	OCIDefine *OraStringDefine = NULL;
	if (OCIDefineByPos(hOraPlsqlStatement, &OraStringDefine, hOraErr, 2, (void *)stringBuffer, (sword)sizeof(stringBuffer), SQLT_STR, (void *)0, (ub2 *)0, (ub2 *)0, OCI_DEFAULT) != OCI_SUCCESS)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to DefineByPos OraUsernameDefine", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to DefineByPos OraUsernameDefine\n");
#endif
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	status = OCIStmtExecute(hOraSvcCtx, hOraPlsqlStatement, hOraErr, (ub4)0, (ub4)0, (CONST OCISnapshot *) NULL, (OCISnapshot *)NULL, OCI_DEFAULT);
	if (status != OCI_SUCCESS && status != OCI_SUCCESS_WITH_INFO)
	{
#ifdef MESSAGEBOX_ERROR_OUTPUT
		MessageBox(MainWindowHandle, L"Application error, SelectDataFromTable function - unable to execute plsql_user_to_list_statement", L"Error", MB_OK | MB_ICONERROR);
#endif
#ifdef CONSOLE_ERROR_OUTPUT
		printf("Application error, SelectDataFromTable function - unable to execute select sql statement\n");
#endif
		checkerr(hOraErr, status);
		OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
		return FALSE;
	}

	printf("id | textfield\n");
	while ((status = OCIStmtFetch2(hOraPlsqlStatement, hOraErr, 1, OCI_DEFAULT, 0, OCI_DEFAULT)) == OCI_SUCCESS || status == OCI_SUCCESS_WITH_INFO)
	{
		printf("%d | %s\n", id, stringBuffer);
	}

	OCIHandleFree(hOraPlsqlStatement, OCI_HTYPE_STMT);
	return TRUE;

}