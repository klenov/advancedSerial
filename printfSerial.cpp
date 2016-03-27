#include "printfSerial.h"

#if defined(DISABLE_PFSERIAL) && DISABLE_PFSERIAL == 1

  void printfSerial::setPrinter(Print &printer) {
    (void)0;
  }

  void printfSerial::setFilter(Level f_level) {
    (void)0;
  }

  void printfSerial::vsnprintfPrint(Level _message_level, const char *format, ...) {
    (void)0;
  }

#else
  void printfSerial::setPrinter(Print &printer) {
    _printer = &printer;
  }

  void printfSerial::setFilter(Level f_level) {
    _filter_level = f_level;
  }

  void printfSerial::vsnprintfPrint(Level _message_level, const char *format, ...) {
    if( _message_level <= _filter_level ) {
      char printf_buffer[printf_buffer_size];

      va_list args;
      va_start(args, format);
      // vsnprintf reference http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html#gaa3b98c0d17b35642c0f3e4649092b9f1
      vsnprintf(printf_buffer, printf_buffer_size, format, args);
      _printer->print(printf_buffer);
    }
  }

#endif

printfSerial pfSerial = printfSerial();