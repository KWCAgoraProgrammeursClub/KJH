#include "sha2.h"

/**
 * Derives a key from a source.
 */
void derive_key
  (unsigned char* source, unsigned len, unsigned char key[ 32 ])
{
  SHA256_CTX ctx;

  sha256_Init(&ctx);
  sha256_Update(&ctx, source, len);
  sha256_Final(&ctx, key);

  for (unsigned i=0; i < 256; i++) {
    sha256_Init(&ctx);
    sha256_Update(&ctx, key, 32);
    sha256_Final(&ctx, key);
  }

#ifdef USE_SECRET
#include "secret.h"
  for (unsigned i=0; i < 32; i++) {
    key[ i ] = secret[ i ] ^ key[ i ];
  }
#endif
}
