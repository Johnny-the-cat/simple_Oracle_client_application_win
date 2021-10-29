#pragma once

#include <windows.h>
#include "oratypes.h"
#include "oci.h"

//Функция получает указатели на функции OCI
BOOL LoadOciFunctions(HMODULE hOCIDll);

//Функция вывода текста ошибки
void checkerr(OCIError *errhp, sword status);

//Функция инициализации хендлов OCI окружения и ошибок. 
BOOL InitOraEnvironment(OCIEnv **hOraEnv, OCIError **hOraErr);
//Функция освобождения хендлов OCI окружения и ошибок. 
void CloseOraEnvironment(OCIEnv *hOraEnv, OCIError *hOraErr);

//Функция создания сессии
BOOL CreateSession(OCIEnv *hOraEnv, OCIError *hOraErr, OCIServer **hOraServer, OCISvcCtx **hOraSvcCtx, OCISession **hOraSession, char *username, char *password, char *dbconnect, BOOL assysdba);

//Функция закрытия сессии
void CloseSession(OCIError *hOraErr, OCIServer *hOraServer, OCISvcCtx *hOraSvcCtx, OCISession *hOraSession);

//Функция для выполнения sql выражения. Не подходит для SELECT, использование для множественных INSERT-ов неоптимально.
BOOL ExecuteStatement(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr, char *statement);

BOOL InsertDataInTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr);

BOOL SelectDataFromTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr);