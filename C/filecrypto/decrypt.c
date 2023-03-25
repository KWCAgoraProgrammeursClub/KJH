#include <stdio.h>
#include <string.h>

#include "functions.h"

int main
  (int argc, char* argv[])
{
  char* pass;
  char* file;
  char* out;
  unsigned char* buf;
  unsigned buf_len;
  unsigned char Ke[ 32 ];
  unsigned char Ka[ 32 ];
  unsigned char* iv;
  unsigned char* hmac;
  unsigned char* payload;

  if (argc < 4) {
    fprintf(stderr, "You need three arguments: password, in, out.\n");
    return ~0;
  }
  pass = argv[ 1 ];
  file = argv[ 2 ];
  out  = argv[ 3 ];

  if (absorb_file(file, &buf, &buf_len)) {
    fprintf(stderr, "Error absorbing file '%s'\n", file);
    return ~0;
  }

  if (buf_len < (32 + 16)) {
    fprintf(stderr, "Error: File too short.\n");
    return ~0;
  }

  derive_key((unsigned char*)pass, strlen(pass), Ke);
  derive_key(Ke, sizeof(Ke), Ka);

  iv = buf;
  payload = buf + 16;
  hmac = buf + buf_len - 32;

  if (decapsulate(out, payload, buf_len - (32 + 16), iv, Ke, Ka, hmac)) {
    fprintf(stderr, "Decapsulation error.\n");
    return ~0;
  }

  return 0;
}
