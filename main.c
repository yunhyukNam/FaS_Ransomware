#include "encrypt.h"

int main() {
    BCRYPT_ALG_HANDLE RNG_HANDLE = NULL;
    BCRYPT_ALG_HANDLE HASH_HANDLE = NULL;
    BCRYPT_ALG_HANDLE PK_HANDLE = NULL;
    BCRYPT_ALG_HANDLE SK_HANDLE = NULL;

    BYTE randomValue[rLength] = { 0x00, };

    genALGhandler(&RNG_HANDLE);
    genRandom(RNG_HANDLE, randomValue);
    printf("genRandom Execute\n");

    genHash(randomValue);
    printf("genHash Execute\n");

    BCryptCloseAlgorithmProvider(RNG_HANDLE, 0);

    return 0;
}