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
  /* Printing "hello, world". */
  aSerial.level(Level::A).println("This message will be printed");       // Level::A is less verbose than the filtering threshold
  aSerial.level(Level::AA).println("This message also will be printed"); // Level::AA is equal to the filtering threshold

  aSerial.level(Level::AAA).println("This message won't be printed");    // Level::AAA is more verbose than the filtering threshold
  aSerial.level(Level::AAAA).println("This message won't be printed");   // Level::AAAA is more verbose than the filtering threshold

  /* The same using short method names. */
  aSerial.l(Level::A).pln("This message will be printed");
  aSerial.l(Level::AA).pln("This message also will be printed");

  aSerial.l(Level::AAA).pln("This message won't be printed");
  aSerial.l(Level::AAAA).pln("This message won't be printed");

  delay(3000);
}
