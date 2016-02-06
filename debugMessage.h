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
        _level_current(Level::OFF),
        _printer(nullptr) {}

    void setPrinter(Print &printer);
    void setLevel(Level level);

    DebugMessage& l(Level level);
    DebugMessage& print_double(double n);
    DebugMessage& printf(const char* msg, ...);

private:
    void va_print(const char *format, va_list args);
    inline bool should_be_printed(void);
};

extern DebugMessage dMessage;
typedef DebugMessage::Level Level;
#endif
