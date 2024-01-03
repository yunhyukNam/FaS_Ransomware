#include <stdio.h>
#include <Windows.h>
#include <bcrypt.h>

#include "type.h"

#define RanLength 32

void genALGhandler(BCRYPT_ALG_HANDLE* hAlgorithm) {
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    if (!NT_SUCCESS(status)) {
        printf("[ERROR] 0xFF' : STATUS IS NOT CLEAR\n");
        exit(1);
    }

    status = BCryptOpenAlgorithmProvider(hAlgorithm, BCRYPT_RNG_ALGORITHM, NULL, 0);
    if (!NT_SUCCESS(status)) {
        printf("[ERROR] 0x%x : BCryptOpenAlgorithmProvider Failed\n", status);
        return;
    }
    return;
}

void genRandom(BCRYPT_ALG_HANDLE RNG_HANDLE, BYTE* byte) {
    BOOL RandomFlag = FALSE;

    NTSTATUS status = STATUS_UNSUCCESSFUL;
    if (!NT_SUCCESS(status)) {
        printf("[ERROR] 0x01 : STATUS IS NOT CLEAR\n");
        exit(1);
    }

    status = BCryptGenRandom(RNG_HANDLE, byte, RanLength, BCRYPT_RNG_USE_ENTROPY_IN_BUFFER);
    if (!NT_SUCCESS(status)) {
        printf("[ERROR] 0x%x : BCryptGenRandom Failed\n", status);
        return;
    }
    else {
        RandomFlag = TRUE;

        if (RandomFlag == TRUE) {
            printf("RANDOM ARRAY : ");

            for (int cnt_i = 0; cnt_i < RanLength; cnt_i++) {
                if (cnt_i % 4 == 0) {
                    printf("\n");
                }
                printf("0x%02x\t", byte[cnt_i]);
            }
            printf("\n");
        }
    }
    return;
}

int main() {
    BCRYPT_ALG_HANDLE RNG_HANDLE = NULL;
    BYTE randomValue[RanLength] = { 0x00, };

    genALGhandler(&RNG_HANDLE);
    genRandom(RNG_HANDLE, randomValue);

    BCryptCloseAlgorithmProvider(RNG_HANDLE, 0);

    return 0;
}
