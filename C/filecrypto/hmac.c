#include "sha2.h"

/**
 * Calculate a SHA2-256 HMAC
 */
void hmac
  (
    unsigned char key[ 32 ],
    unsigned char* data,
    unsigned data_length,
    unsigned char hmac[ 32 ]
  )
{
  unsigned char intermediate[ 32 ];
  SHA256_CTX ctx;

  sha256_Init(&ctx);
  sha256_Update(&ctx, key, 32);
  sha256_Update(&ctx, data, data_length);
  sha256_Final(&ctx, intermediate);

  sha256_Init(&ctx);
  sha256_Update(&ctx, key, 32);
  sha256_Update(&ctx, intermediate, 32);
  sha256_Final(&ctx, hmac);

}
