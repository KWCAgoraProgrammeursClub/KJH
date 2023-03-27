#include <stdio.h>
#include <string.h>

#include "aes.h"
#include "sha2.h"
#include "functions.h"

int decapsulate
  (
    char* path,
    unsigned char* ciphertext,
    unsigned ciphertext_length,
    unsigned char* iv,
    unsigned char* Ke,
    unsigned char* Ka,
    unsigned char* hmac
  )
{
  FILE* file;
  struct AES_ctx aes;
  SHA256_CTX sha;
  unsigned char tmp[ 16 ];
  unsigned char hmac_compare[ 32 ];

  if ((file = fopen(path, "w")) == 0) {
    fprintf(stderr, "Could not open '%s' for writing.\n", path);
    return ~0;
  }

  sha256_Init(&sha);
  sha256_Update(&sha, Ka, 32);
  sha256_Update(&sha, iv, 16);
  sha256_Update(&sha, ciphertext, ciphertext_length);
  sha256_Final(&sha, hmac_compare);

  sha256_Init(&sha);
  sha256_Update(&sha, Ka, 32);
  sha256_Update(&sha, hmac_compare, 32);
  sha256_Final(&sha, hmac_compare);

  if (0 != safe_memcmp(hmac, hmac_compare, 32)) {
    fprintf(stderr, "HMAC comparison fails.\n");
    return ~0;
  }

  AES_init_ctx_iv(&aes, Ke, iv);

  while (ciphertext_length >= 16) {
    memcpy(tmp, ciphertext, 16);
    AES_CTR_xcrypt_buffer(&aes, tmp, 16);
    fwrite(tmp, 1, 16, file);
    ciphertext += 16;
    ciphertext_length -= 16;
  }
  if (ciphertext_length) {
    memcpy(tmp, ciphertext, ciphertext_length);
    AES_CTR_xcrypt_buffer(&aes, tmp, ciphertext_length);
    fwrite(tmp, 1, ciphertext_length, file);
  }

  fclose(file);

  return 0;
}
