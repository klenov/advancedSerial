/* debugMessage Library - Basic Example */

#include <debugMessage.h>

int    counter = 0;

void setup() {
  Serial.begin(9600);

  dMessage.setPrinter(Serial);
  dMessage.setLevel(Level::INFO); // set verbosity level, could be OFF, ERROR, INFO, DEBUG, VERBOSE
}

void loop() {
  /* The following message will be printed at Level::INFO */
  dMessage.l(Level::INFO).printf("counter = %d" CR, counter);
  counter += 1;

  /* The following message will be printed only after setLevel(Level::VERBOSE) */
  dMessage.l(Level::VERBOSE).printf("End of loop()" CR);
  delay(200);
}
