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
  unsigned char iv[ 16 ] = { 0 };

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

  derive_key((unsigned char*)pass, strlen(pass), Ke);
  derive_key(Ke, sizeof(Ke), Ka);
  random_iv(iv, iv);
  random_iv(Ke, iv);

  if (encapsulate(out, buf, buf_len, iv, Ke, Ka)) {
    fprintf(stderr, "Error in encryption.\n");
  }

  return 0;
}
