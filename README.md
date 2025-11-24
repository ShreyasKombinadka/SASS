# SASS — Single Asynchronous Serial Stream Protocol

SASS is a minimal, single-wire, low-speed asynchronous protocol for microcontroller communication.  
This a library provides a simple transmitter and receiver implementation.

**Version : 1.0.1**

---

## Features
- Single-wire simplex link  
- Idle = HIGH  
- Start/Stop = LOW  
- LSB-first  
- Fully software-based  
- Suitable for slow, lightweight communication

---

## Installation

### Arduino IDE
1. Download the repository as a ZIP  
2. Open **Sketch → Include Library → Add .ZIP Library**

### PlatformIO
Add to `platformio.ini`:

```
lib_deps =
    https://github.com/<your_username>/SASS
```

---

## Examples

### Transmit
```cpp
#include <SASS.h>

void setup() {
    uint64_t frame_t = 0b101101;
    SASS_transmitter(5, 200, 6, frame_t);
}

void loop() {}
```

### Receive
```cpp
#include <SASS.h>

uint64_t frame_r = 0;

void setup() {
    pinMode(4, INPUT);
}

void loop() {
    SASS_receiver(4, 200, 6, frame_r);
}
```

---

## API Reference

### `void SASS_transmitter(int pin, unsigned long T_us, int bit_len, uint64_t frame);`
Transmits a frame using SASS protocol.

### `void SASS_receiver(int pin, unsigned long T_us, int bit_len, uint64_t &frame);`
Receives a frame and writes the value into `frame`.

---

## Frame Format

```
Idle ─ HIGH
Start ─ LOW
Data  ─ L bits (LSB first) with each bit being active T time.
Stop  ─ LOW
Idle ─ HIGH
```

---

## License
MIT License
