/* debugMessage Library - Advanced Example
   based on https://github.com/mrRobot62/Arduino-logging-library
 */

#include <debugMessage.h>

int   int_1  =    123,  int_2 =    345;
long  long_1 = 111111, long_2 = 222222;
bool  bool_1 =   true, bool_2 =  false;

const char* str_1 = "this is a string";

void setup() {
  Serial.begin(9600);

  dMessage.setPrinter(Serial);
  dMessage.setLevel(Level::VERBOSE); // set verbosity level, could be OFF, ERROR, INFO, DEBUG, VERBOSE
}

void loop() {
  dMessage.l(Level::INFO).printf(" * debugMessage library advanced example * " CR);


  /* Printing different types */
  /* int */
  dMessage.l(Level::INFO).printf("Integers int_1 = %d, int_2 = %d" CR,        int_1, int_2);
  dMessage.l(Level::INFO).printf("Hex integers int_1 = %x, int_2 = %X" CR,     int_1, int_2);
  dMessage.l(Level::INFO).printf("Binary integers int_1 = %b, int_2 = %B" CR, int_1, int_2);

  /* long */
  dMessage.l(Level::INFO).printf("Longs long_1 %l, long_1 = %l" CR, long_1, long_2);

  /* bool */
  dMessage.l(Level::INFO).printf("Booleans bool_1 = %t, bool_2 = %T" CR, bool_1, bool_2);

  /* string */
  dMessage.l(Level::INFO).printf("String: %s" CR, str_1);
  dMessage.l(Level::ERROR).printf("Sample error message." CR);

  dMessage.l(Level::INFO).printf("%d, %d, %l, %l, %t, %T" CR CR, int_1, int_2, long_1, long_2, bool_1, bool_2);

  delay(5000);
}
