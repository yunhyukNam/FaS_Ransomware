#include <openssl/sha.h>

#include "encrypt.h"

void genALGhandler(BCRYPT_ALG_HANDLE* hAlgorithm) {
    NTSTATUS status = STATUS_UNSUCCESSFUL;
    if (NT_SUCCESS(status)) {
        printf("[ERROR] 0x0F : STATUS IS NOT CLEAR\n");
        exit(1);
    }

    status = BCryptOpenAlgorithmProvider(hAlgorithm, BCRYPT_RNG_ALGORITHM, NULL, 0);
    if (!NT_SUCCESS(status)) {
        printf("[ERROR] %x : BCryptOpenAlgorithmProvider Failed\n", status);
        return;
    }
    return;
}

void genRandom(BCRYPT_ALG_HANDLE RNG_HANDLE, BYTE* byte) {
    BOOL RandomFlag = FALSE;

    NTSTATUS status = STATUS_UNSUCCESSFUL;

    status = BCryptGenRandom(RNG_HANDLE, byte, rLength, BCRYPT_RNG_USE_ENTROPY_IN_BUFFER);
    if (!NT_SUCCESS(status)) {
        printf("[ERROR] %x : BCryptGenRandom Failed\n", status);
        return;
    }
    else {
        RandomFlag = TRUE;

        if (RandomFlag == TRUE) {
            printf("RANDOM ARRAY : ");

            for (int cnt_i = 0; cnt_i < rLength; cnt_i++) {
                if (cnt_i % 4 == 0) {
                    printf("\n\t");
                }
                printf("0x%02x\t", byte[cnt_i]);
            }
            printf("\n");
        }
    }
    return;
}

void genHash(BYTE* byte) {
    unsigned char Result[rLength];
    SHA256(byte, sizeof(byte), Result);

    printf("SHA-256 Hash: ");
    for (int i = 0; i < rLength; ++i) {
        printf("%02x", Result[i]);
    }
    printf("\n");
}

//void genPK(BCRYPT_ALG_HANDLE PK_HANDLE, BYTE* byte) {
//    BCRYPT_KEY_HANDLE pkKey = NULL;
//    NTSTATUS status = STATUS_UNSUCCESSFUL;
//
//    status = BCryptGenerateKeyPair(PK_HANDLE, pkKey, BCRYPT_RSA_ALGORITHM, 0);
//
//    if (!NT_SUCCESS(status)) {
//        printf("[ERROR] %x : BCryptGenerateKeyPair Failed\n", status);
//    }
//}

void genSK(BCRYPT_ALG_HANDLE SK_HANDLE, BYTE* byte) {

}