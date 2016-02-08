# advancedSerial

This library provides some additions to regular `Serial.print()`:

**1. Chainable `print()` and `println()` methods:**

```Arduino
// Instead of
Serial.print("x = ");
Serial.print(x);
Serial.print("y = ");
Serial.println(y);

// you can chain print() and println() methods
aSerial.print("x = ").print(x).print("y = ").println(y);

// also short method names are available
aSerial.p("x = ").p(x).p("y = ").pln(y);
```
You cand find a basic example [here](https://github.com/klenov/advancedSerial/blob/master/examples/Basic/Basic.ino).

**2. Verbosity levels:**
There are four verbosity levels. The order in terms of verbosity, from least to most is `A, AA, AAA, AAAA`. You can choose at wich verbosity level a message will be printed and also set a filtering threshold. Only the masseges less or equally verbose to the treshold level will be printed. 
Maybe is't easier to see by the example:
```Arduino
void setup() {
  Serial.begin(9600);

  aSerial.setPrinter(Serial);
  aSerial.setFilter(Level::AA); // The filtering threshold is set to Level::AA
}

void loop() {
  aSerial.level(Level::A).println("This message will be printed");       // Level::A is less verbose than the filtering threshold
  aSerial.level(Level::AA).println("This message also will be printed"); // Level::AA is equal to the filtering threshold
  
  aSerial.level(Level::AAA).println("This message won't be printed");    // Level::AAA is more verbose than the filtering threshold
  aSerial.level(Level::AAAA).println("This message won't be printed");   // Level::AAAA is more verbose than the filtering threshold
  
  // also short method names are available
  aSerial.l(Level::AAAA).p("Oops! ").pln("This message won't be printed");
}
```
You cand find a complete example [here](https://github.com/klenov/advancedSerial/blob/master/examples/Advanced/Advanced.ino).

You should have Arduino IDE 1.5.8 or newer to use this library or you can [manually enable C++11 in the configuration files](https://arduino.land/FAQ/content/2/49/en/can-c11-be-used-with-arduino.html).

# Pulic Methods
| Method               | Short alias | Description                                                   |
|----------------------|-------------|---------------------------------------------------------------|
| `setPrinter(Print)`  |             | `Print` could be a hardware or software serial                |
| `setFilter(Level)`   |             | `Level` could be one of `Level::A`, `Level::AA`, ..., `Level::AAAA`|
| `off()`              |             | Disables the output                                           |
| `on()`               |             | Enables the output                                            |
| `level(Level)`       | `l(Level)`  | Sets the message verbosity level                              |
| `print(x)`            |    `p(x)`    | The same functionality as `Serial.print()`                    |
| `println(x)`          |    `pln(x)`  | The same functionality as `Serial.println()`                  |


## Tested with
* Arduino Uno
* Arduino Nano
* Arduino Pro Micro
* Arduino Mega 2560
* Teensy 3.1
* NodeMCU 1.0

At this time this library doesn't work on Arduino Due.

## Similar libraries
* http://playground.arduino.cc/Code/SerialDebugger
* https://github.com/felixstorm/AvrArdLogging
* https://github.com/dhylands/Arduino-logging-library



