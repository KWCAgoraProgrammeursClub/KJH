/**
 * Implements time-safe memory comparison.
 * Cannot be used for sorting.
 */
int safe_memcmp
  (unsigned char* mem1, unsigned char* mem2, unsigned size)
{
  unsigned nsame = 0;

  for (unsigned i=0; i < size; i++) {
    if ((mem2[ i ] - mem1[ i ]) == 0) {
      nsame += 4;
    } else {
      nsame += 2;
    }
  }
  if (nsame != (size * 4)) {
    return ~0;
  } else {
    return 0;
  }
}
