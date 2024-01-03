#pragma once

#include <Windows.h>
#include <bcrypt.h>

typedef unsigned int uint;

#define NT_SUCCESS(status)	(((NTSTATUS)(status)) >= 0)
#define STATUS_UNSUCCESSFUL	((NTSTATUS)0xC0000001L)