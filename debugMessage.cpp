#include "DebugMessage.h"

void DebugMessage::setPrinter(Print &printer) {
  _printer = &printer;
}
void DebugMessage::setLevel(DebugMessage::Level level) {
  _level = level;
}

DebugMessage& DebugMessage::l(DebugMessage::Level level) {
  _level_current = level;
  return *this;
}

DebugMessage& DebugMessage::print(const char* msg) {
  if (_level_current <= _level) {
    _printer->print(msg);
  }
  return *this;
}

DebugMessage& DebugMessage::println(const char* msg) {
  if (_level_current <= _level) {
    _printer->println(msg);
  }
  return *this;
}

DebugMessage& DebugMessage::printf(const char* msg, ...) {
  if (_level_current <= _level) {
    va_list args;
    va_start(args, msg);
    va_print(msg, args);
  }
  return *this;
}

void DebugMessage::va_print(const char *format, va_list args) {
  // loop through format string
  for (; *format != 0; ++format) {

    if (*format == '%') {
      ++format;
      if (*format == '\0') break;
      if (*format == '%') {
        _printer->print(*format);
        continue;
      }

      switch( *format ) {

        case 's': {
          register char *s = (char *)va_arg( args, int );
          _printer->print(s);
          continue; }

        case 'd': case 'i': {
          _printer->print(va_arg( args, int ), DEC);
          continue; }

        case 'x': case 'X': {
          if(*format == 'X')
            _printer->print("0x");
          _printer->print(va_arg( args, int ), HEX);
          continue; }

        case 'b': case 'B': {
          if(*format == 'B')
            _printer->print("0b");
          _printer->print(va_arg( args, int ), BIN);
          continue; }

        case 'l': {
          _printer->print(va_arg( args, long ), DEC);
          continue; }

        case 'c': {
          _printer->print(va_arg( args, int ));
          continue; }

        case 't': {
          if (va_arg( args, int ) == 1)
            _printer->print("T");
          else
            _printer->print("F");
          continue; }

        case 'T': {
          if (va_arg( args, int ) == 1)
            _printer->print("true");
          else
            _printer->print("false");
          continue; }

      }
    }
    else if (*format == '\n') {
        _printer->print('\r');
    }
    _printer->print(*format);
  }
}

DebugMessage dMessage = DebugMessage();
