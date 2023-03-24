#include <stdlib.h>
#include <time.h>

void random_iv
  (unsigned char in[ 16 ], unsigned char iv[ 16 ])
{
  srand(time(0));
  for (unsigned i=0; i < 16; i++) {
    iv[ i ] = in[ i ] ^ (rand() % 256);
  }
}
