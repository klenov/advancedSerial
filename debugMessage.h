#ifndef DEBUG_MESSAGES
#define DEBUG_MESSAGES

#include <inttypes.h>
#include <stdarg.h>

#include "Arduino.h"

#define CR "\n"

class DebugMessage {
public:
    enum Level { OFF, ERROR, INFO, DEBUG, VERBOSE };
private:
    Level   _level;
    Level   _level_current;
    Print*  _printer;

    inline bool should_be_printed() { return _level_current <= _level; }
public:
    /*! * default Constructor */
    DebugMessage()
      : _level(Level::OFF),
        _level_current(Level::OFF),
        _printer(nullptr) {}

    void setPrinter(Print &printer) {
      _printer = &printer;
    }

    void setLevel(Level v_level) {
      _level = v_level;
    }

    DebugMessage& level(Level v_level) {
      _level_current = v_level;
      return *this;
    }
    inline DebugMessage& l(Level v_level) {return level(v_level);}

    template <typename Type>
    DebugMessage& print(Type tX) {
      if ( should_be_printed() ) {
        _printer->print(tX);
      }
      return *this;
    }

    template <typename Type>
    DebugMessage& p(Type tX) {
      return print(tX);
    }

    template <typename Type>
    DebugMessage& println(Type tX) {
      if( should_be_printed() ) {
        print(tX);
        _printer->println();
      }
      return *this;
    }

    template <typename Type>
    DebugMessage& pln(Type tX) {
      return println(tX);
    }

    DebugMessage& print(long n, int base) {
      if ( should_be_printed() ) {
        _printer->print(n, base);
      }
      return *this;
    }
    inline DebugMessage& p(long n, int base) {return print(n, base);}

    DebugMessage& println(long n, int base) {
      if ( should_be_printed() ) {
        print(n, base);
        _printer->println();
      }
      return *this;
    }
    inline DebugMessage& pln(long n, int base) {return println(n, base);}
};

DebugMessage dMessage = DebugMessage();

extern DebugMessage dMessage;
typedef DebugMessage::Level Level;
#endif
