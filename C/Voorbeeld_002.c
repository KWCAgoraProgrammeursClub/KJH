/**
 In C wordt ieder source code bestand door twee processen heen gehaald: de precompiler en de compiler zelf.
 (Dit geldt ook voor C++ trouwens)
 De precompiler is het ding dat alle door '#' voorafgegane tokens verwerkt, zoals:
 
 #include
 #ifdef
 #ifndef
 #endif
 #define
 
 De precompiler taal is eigenlijk een aparte taal op zichzelf (en is ook iets complexer dan je misschien denkt
 afgaande op het bovenstaande).
 
 Voorbeeld:
 */

#include <stdio.h>

int main
  (int argc, char* argv[])
{
  for (int i=0; i < argc; i++) {
    fprintf(stderr, "Your argument %d was '%s'\n", i, argv[ i ]);
  }
  return 0;
}

/**
 Wat hier gebeurt: de precompiler laadt de 'header-file' stdio.h in. Die staat ergens binnen een vooraf voor de
 compiler te doorzoeken lijst van directories (in Linux meestal /usr/include), en plaatst de inhoud van dit
 bestand op de plek van de #include definitie. Wat het programma voor de rest doet, kun je achterhalen door het
 te compileren: cc myfile.c -o myapp && ./myapp hello arg2 arg3
 
 (Ofzo)
 
*/
