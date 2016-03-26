/*
   advancedSerial Library - Advanced Example
   https://github.com/klenov/advancedSerial
*/

#include <advancedSerial.h>

void setup() {
  Serial.begin(9600);

  aSerial.setPrinter(Serial);
  aSerial.setFilter(Level::vv);
  /* Uncomment the following line to disable the output. By defalut the ouput is on. */
  // aSerial.off();
}

void loop() {
  // This message will be printed
  aSerial.level(Level::v).println("Level::v is less verbose than the filtering threshold");
  // This message also will be printed
  aSerial.level(Level::vv).println("Level::vv is equal to the filtering threshold");

  // This message won't be printed
  aSerial.level(Level::vvv).println("Level::vvv is more verbose than the filtering threshold");
  // This message won't be printed
  aSerial.level(Level::vvvv).println("Level::vvvv is more verbose than the filtering threshold");

  /* The same using short method names. */
  aSerial.l(Level::v).pln("This message will be printed");
  aSerial.l(Level::vv).pln("This message also will be printed");

  aSerial.l(Level::vvv).pln("This message won't be printed");
  aSerial.l(Level::vvvv).pln("This message won't be printed");

  aSerial.l(Level::v).p("Look! ").pln("This message will be printed");

  // Two empty lines
  aSerial.l(Level::v).println().pln();

  // printf based output
  int  foo =  1729;
  long bar = 65536;
  print_v("printf based output:\n");
  print_v("foo as hex = 0x%X, bar as hex = 0x%lx \n", foo, bar);
  print_vv("level vv\n");
  print_vvv("level vvv\n");
  print_vvvv("level vvvv\n");
  
  // very long string, first PRINT_BUFFER_SIZE characters will be printed
  print_v("012345678901234567890123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  print_v("\n");

  delay(3000);
}
