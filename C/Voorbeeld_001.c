/**
 In C begint ieder gewoon programma met een standaard functie: main.
*/

int main
  (int argc, char* argv[])
{
  return 0;
}

/**
 Zo dus. Dit programma doet niks, overigens (behalve een code teruggeven aan het systeem). De onderdelen zijn:
 
 int main  -- het programma retourneert een getal aan degene die het programma opstart. Meestal is dit een shell.
              Het getal dat hier geretourneerd wordt, kun je in de shell opvragen bijv door 'echo $?'.
              
 (int argc, char* argv[])  -- dit is de array can command line arguments die bijvoorbeeld door een shell
                              gegeven kunnen worden. argv[ 0 ] bevat de naam van de executable zelf,
                              argv[ 1 ] etc bevatten de rest van de arguments.
                              
 return 0;  -- hiermee geeft het programma dus de exit code terug aan het systeem. Als je hier '1' van maakt,
               dan zal 'echo $?' in de shell dus 1 geven.
 
*/
