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
public:
  /*! * default Constructor */
    DebugMessage()
      : _level(Level::OFF),
        _level_current(Level::INFO),
        _printer(nullptr) {}

    void setPrinter(Print &printer);
    void setLevel(Level level);

    DebugMessage& l(Level level);
    DebugMessage& print(const char* msg);
    DebugMessage& println(const char* msg);
    DebugMessage& printf(const char* msg, ...);

private:
    void va_print(const char *format, va_list args);
};

extern DebugMessage dMessage;
typedef DebugMessage::Level Level;
#endif
