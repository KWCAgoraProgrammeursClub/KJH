#include <stdio.h>
#include <string.h>

#include "aes.h"
#include "sha2.h"

int encapsulate
  (
    char* path,
    unsigned char* payload,
    unsigned payload_size,
    unsigned char iv[ 16 ],
    unsigned char Ke[ 32 ],
    unsigned char Ka[ 32 ]
  )
{
  FILE* file;
  struct AES_ctx aes;
  SHA256_CTX sha;
  unsigned char tmp[ 16 ];
  unsigned char hmac[ 32 ];

  if ((file = fopen(path, "w")) == 0) {
    fprintf(stderr, "Could not open '%s' for writing.\n", path);
    return ~0;
  }

  sha256_Init(&sha);
  sha256_Update(&sha, Ka, 32);
  sha256_Update(&sha, iv, 16);
  fwrite(iv, 1, 16, file);

  AES_init_ctx_iv(&aes, Ke, iv);
  while (payload_size >= 16) {
    memcpy(tmp, payload, 16);
    AES_CTR_xcrypt_buffer(&aes, tmp, 16);
    sha256_Update(&sha, tmp, 16);
    fwrite(tmp, 1, 16, file);
    payload += 16;
    payload_size -= 16;
  }
  if (payload_size) {
    memcpy(tmp, payload, payload_size);
    AES_CTR_xcrypt_buffer(&aes, tmp, payload_size);
    sha256_Update(&sha, tmp, payload_size);
    fwrite(tmp, 1, payload_size, file);
  }
  sha256_Final(&sha, hmac);

  sha256_Init(&sha);
  sha256_Update(&sha, Ka, 32);
  sha256_Update(&sha, hmac, 32);
  sha256_Final(&sha, hmac);

  fwrite(hmac, 1, 32, file);

  fclose(file);

  return 0;
}
