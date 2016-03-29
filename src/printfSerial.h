/*
   advancedSerial Library
   https://github.com/klenov/advancedSerial
*/

#ifndef PRINTF_SERIAL
#define PRINTF_SERIAL

#include "Arduino.h"

enum class Level { v, vv, vvv, vvvv };

#define PRINT_BUFFER_SIZE 80


#if defined(DISABLE_PFSERIAL) && DISABLE_PFSERIAL == 1
  #define print_v(fmt, ...)    ( (void)0 )
  #define print_vv(fmt, ...)   ( (void)0 )
  #define print_vvv(fmt, ...)  ( (void)0 )
  #define print_vvvv(fmt, ...) ( (void)0 )
#else
  #define print_v(fmt, ...)    ( pfSerial.vsnprintfPrint(Level::v, fmt, ## __VA_ARGS__) )
  #define print_vv(fmt, ...)   ( pfSerial.vsnprintfPrint(Level::vv, fmt, ## __VA_ARGS__) )
  #define print_vvv(fmt, ...)  ( pfSerial.vsnprintfPrint(Level::vvv, fmt, ## __VA_ARGS__) )
  #define print_vvvv(fmt, ...) ( pfSerial.vsnprintfPrint(Level::vvvv, fmt, ## __VA_ARGS__) )
#endif

class printfSerial {
private:

    Level _filter_level;
    const Level default_filter_level = Level::v;

    Print*  _printer;

    static const int printf_buffer_size = PRINT_BUFFER_SIZE;

public:
    /*! * default Constructor */
    printfSerial()
      : _filter_level(default_filter_level),
        _printer(nullptr) {}

    void setPrinter(Print&);

    void setFilter(Level);

    void vsnprintfPrint(Level, const char*, ...);
};

extern printfSerial pfSerial;
#endif

