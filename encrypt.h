#pragma once

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>
#include <bcrypt.h>

typedef unsigned int uint;

#define NT_SUCCESS(status)	(((NTSTATUS)(status)) >= 0)
#define STATUS_UNSUCCESSFUL	((NTSTATUS)0xC0000001L)

#define rLength 32

void genALGhandler(BCRYPT_ALG_HANDLE* hAlgorithm);
void genRandom(BCRYPT_ALG_HANDLE RNG_HANDLE, BYTE* byte);
void genHash(BYTE* byte);
void genPK(BCRYPT_ALG_HANDLE HASH_HANDLE, BYTE* byte);
void genSK(BCRYPT_ALG_HANDLE HASH_HANDLE, BYTE* byte);