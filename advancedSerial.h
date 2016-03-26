/*
   advancedSerial Library
   https://github.com/klenov/advancedSerial
*/

#ifndef ADVANCED_SERIAL
#define ADVANCED_SERIAL

#define PRINT_BUFFER_SIZE 80

#define print_v(fmt, ...)    (  aSerial.level(Level::v).vsnprintfPrint(fmt, ## __VA_ARGS__) )
#define print_vv(fmt, ...)   (  aSerial.level(Level::vv).vsnprintfPrint(fmt, ## __VA_ARGS__) )
#define print_vvv(fmt, ...)  (  aSerial.level(Level::vvv).vsnprintfPrint(fmt, ## __VA_ARGS__) )
#define print_vvvv(fmt, ...) (  aSerial.level(Level::vvvv).vsnprintfPrint(fmt, ## __VA_ARGS__) )

#include <stdarg.h>
#include "Arduino.h"

class advancedSerial {
public:
    enum class Level { v, vv, vvv, vvvv };
private:
    bool _output_enabled;

    Level _filter_level;
    const Level default_filter_level = Level::v;

    Level _message_level;
    const Level default_message_level = Level::v;

    Print*  _printer;

    static const int printf_buffer_size = PRINT_BUFFER_SIZE;

    inline bool should_be_printed(void) { return _output_enabled && ( _message_level <= _filter_level ); }
public:
    /*! * default Constructor */
    advancedSerial()
      : _output_enabled(true),
        _filter_level(default_filter_level),
        _message_level(default_message_level),
        _printer(nullptr) {}

    void setPrinter(Print &printer) {
      _printer = &printer;
    }

    void setFilter(Level f_level) {
      _filter_level = f_level;
    }

    void on(void)  { _output_enabled = true;  }
    void off(void) { _output_enabled = false; }

    advancedSerial& level(Level m_level) {
      _message_level = m_level;
      return *this;
    }
    inline advancedSerial& l(Level m_level) { return level(m_level); }

    template <typename Type>
    advancedSerial& print(Type tX) {
      if ( should_be_printed() ) {
        _printer->print(tX);
      }
      return *this;
    }

    template <typename Type>
    advancedSerial& p(Type tX) {
      return print(tX);
    }

    template <typename Type>
    advancedSerial& println(Type tX) {
      if( should_be_printed() ) {
        print(tX);
        _printer->println();
      }
      return *this;
    }

    template <typename Type>
    advancedSerial& pln(Type tX) {
      return println(tX);
    }

    advancedSerial& print(long n, int base) {
      if ( should_be_printed() ) {
        _printer->print(n, base);
      }
      return *this;
    }
    inline advancedSerial& p(long n, int base) { return print(n, base); }

    advancedSerial& println(long n, int base) {
      if ( should_be_printed() ) {
        print(n, base);
        _printer->println();
      }
      return *this;
    }
    inline advancedSerial& pln(long n, int base) { return println(n, base); }

    advancedSerial& println(void) {
      if ( should_be_printed() ) {
        _printer->println();
      }
      return *this;
    }
    inline advancedSerial& pln(void) { return println(); }

    void vsnprintfPrint(const char *format, ...) {
      char printf_buffer[printf_buffer_size];

      va_list args;
      va_start(args, format);
      // vsnprintf reference http://www.nongnu.org/avr-libc/user-manual/group__avr__stdio.html#gaa3b98c0d17b35642c0f3e4649092b9f1
      vsnprintf(printf_buffer, printf_buffer_size, format, args);
      print(printf_buffer);
    }
};

advancedSerial aSerial = advancedSerial();

extern advancedSerial aSerial;
typedef advancedSerial::Level Level;
#endif
