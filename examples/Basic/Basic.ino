/* debugMessage Library - Basic Example */

#include <debugMessage.h>

int counter = 0;

void setup() {
  Serial.begin(9600);

  dMessage.setPrinter(Serial);
  dMessage.setLevel(Level::DEBUG); // set verbosity level, could be OFF, ERROR, INFO, DEBUG, VERBOSE
}

void loop() {
  /* This message will be printed at Level::INFO */
  dMessage.level(Level::INFO).print("counter = ").println(counter);

  /* The same with method aliases */
  dMessage.l(Level::INFO).p("counter = ").pln(counter);

  /* Of course you can still use good old Serial.print() */
  Serial.print("counter = ");
  Serial.println(counter);

  dMessage.pln("This message is at Level::INFO, since printing level hasn't been changed since last call to dMessage.level()");
  dMessage.l(Level::DEBUG).pln("This message is at Level::DEBUG");

  dMessage.l(Level::VERBOSE).p("This message won't be printed until level is not set to Level::VERBOSE");

  counter += 1;
  delay(3000);
}
