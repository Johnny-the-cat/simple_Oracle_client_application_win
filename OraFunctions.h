#pragma once

#include <windows.h>
#include "oratypes.h"
#include "oci.h"

//������� �������� ��������� �� ������� OCI
BOOL LoadOciFunctions(HMODULE hOCIDll);

//������� ������ ������ ������
void checkerr(OCIError *errhp, sword status);

//������� ������������� ������� OCI ��������� � ������. 
BOOL InitOraEnvironment(OCIEnv **hOraEnv, OCIError **hOraErr);
//������� ������������ ������� OCI ��������� � ������. 
void CloseOraEnvironment(OCIEnv *hOraEnv, OCIError *hOraErr);

//������� �������� ������
BOOL CreateSession(OCIEnv *hOraEnv, OCIError *hOraErr, OCIServer **hOraServer, OCISvcCtx **hOraSvcCtx, OCISession **hOraSession, char *username, char *password, char *dbconnect, BOOL assysdba);

//������� �������� ������
void CloseSession(OCIError *hOraErr, OCIServer *hOraServer, OCISvcCtx *hOraSvcCtx, OCISession *hOraSession);

//������� ��� ���������� sql ���������. �� �������� ��� SELECT, ������������� ��� ������������� INSERT-�� ������������.
BOOL ExecuteStatement(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr, char *statement);

BOOL InsertDataInTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr);

BOOL SelectDataFromTable(OCISvcCtx *hOraSvcCtx, OCIEnv *hOraEnv, OCIError *hOraErr);