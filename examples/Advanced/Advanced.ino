/*
   advancedSerial Library - Advanced Example
   https://github.com/klenov/advancedSerial
*/

#include <advancedSerial.h>

int counter = 0;

void setup() {
  Serial.begin(9600);

  aSerial.setPrinter(Serial);
  aSerial.setFilter(Level::AA);
  /* Uncomment the following line to disable the output. By defalut the ouput is on. */
  // aSerial.off();
}

void loop() {
  // This message will be printed
  aSerial.level(Level::A).println("Level::A is less verbose than the filtering threshold");
  // This message also will be printed
  aSerial.level(Level::AA).println("Level::AA is equal to the filtering threshold");

  // This message won't be printed
  aSerial.level(Level::AAA).println("Level::AAA is more verbose than the filtering threshold");
  // This message won't be printed
  aSerial.level(Level::AAAA).println("Level::AAAA is more verbose than the filtering threshold");

  /* The same using short method names. */
  aSerial.l(Level::A).pln("This message will be printed");
  aSerial.l(Level::AA).pln("This message also will be printed");

  aSerial.l(Level::AAA).pln("This message won't be printed");
  aSerial.l(Level::AAAA).pln("This message won't be printed");

  aSerial.l(Level::A).p("Look! ").pln("This message will be printed");

  delay(3000);
}
