#ifndef DEBUG_MESSAGES
#define DEBUG_MESSAGES

#include <inttypes.h>
#include <stdarg.h>

#include "Arduino.h"

#define CR "\n"

class DebugMessage {
public:
    enum Level { NOOUTPUT, ERROR, INFO, DEBUG, VERBOSE };
private:
    Level   _level;
    Level   _level_current;
    Print*  _printer;
public:
  /*! * default Constructor */
    DebugMessage()
      : _level(Level::NOOUTPUT),
        _level_current(Level::NOOUTPUT),
        _printer(nullptr) {}

    void setPrinter(Print &printer);
    void setLevel(Level level);

    DebugMessage& level(Level level);
    DebugMessage& print(const char* msg);
    DebugMessage& println(const char* msg);
    DebugMessage& printf(const char* msg, ...);

private:
    void va_print(const char *format, va_list args);
};

extern DebugMessage debugMessage;
typedef DebugMessage::Level Level;
#endif
