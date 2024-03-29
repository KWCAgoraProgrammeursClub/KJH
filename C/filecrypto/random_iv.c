#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void random_iv
  (unsigned char in[ 16 ], unsigned char iv[ 16 ])
{
#ifdef TRUE_RANDOM
  FILE* rnd = fopen("/dev/random", "r");
  unsigned char tmp[ 16 ];
  int r = fread(tmp, 1, 16, rnd);
  fclose(rnd);
  if (r == 16) {
    for (unsigned i=0; i < 16; i++) {
      iv[ i ] = in[ i ] ^ tmp[ i ];
    }
    return;
  } else {
    fprintf(stderr, "Could not read 16 bytes of system random. Aborting.\n");
    abort();
  }
#endif

  srand(time(0));
  for (unsigned i=0; i < 16; i++) {
    iv[ i ] = in[ i ] ^ (rand() % 256);
  }
}
