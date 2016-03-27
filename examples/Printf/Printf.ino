/*
   advancedSerial Library - printf Example
   https://github.com/klenov/advancedSerial
*/

#define DISABLE_PFSERIAL 0 // set it to 1 to disable messages and reduce memory footprint
#define CR "\r\n"

#include <printfSerial.h>

void setup() {
  Serial.begin(9600);

  pfSerial.setPrinter(Serial);
  pfSerial.setFilter(Level::vv);
}

void loop() {

  // printf based output
  int  foo =  1729;
  long bar = 65536;
  print_v("printf based output --------------------------->" CR);

  print_v("foo = %d, bar = %ld " CR, foo, bar);
  print_v("foo as hex = 0x%X, bar as hex = 0x%lx" CR CR, foo, bar);

  print_vv("level vv" CR);
  print_vvv("level vvv" CR);
  print_vvvv("level vvvv" CR CR);
  
  // very long string, first PRINT_BUFFER_SIZE characters are printed
  print_v("very long string: 012345678901234567890123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
  print_v(CR CR CR);

  delay(3000);
}
