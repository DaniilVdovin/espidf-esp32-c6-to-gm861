# Wiring Diagram — GM861-LED to ESP32-C6

```
  ┌─────────────────┐          ┌─────────────────┐
  │   GM861-LED     │          │    ESP32-C6     │
  │                 │          │                 │
  │  TX (white)  ●──┼──────────┼──● GPIO 18 (RX) │
  │                 │          │                 │
  │  RX (green)  ●──┼──────────┼──● GPIO 19 (TX) │
  │                 │          │                 │
  │  VCC (red)   ●──┼──────────┼──● 3.3V         │
  │                 │          │                 │
  │  GND (black) ●──┼──────────┼──● GND          │
  └─────────────────┘          └─────────────────┘
```

## Pin details

| GM861-LED wire (mb) | GM861-LED pin | ESP32-C6 pin | Notes                     |
|----------------|---------------|--------------|---------------------------|
| White          | TX (output)   | GPIO 18      | Scanner → ESP             |
| Green          | RX (input)    | GPIO 19      | ESP → Scanner             |
| Red            | VCC           | 3.3V         | Power, not 5V!            |
| Black          | GND           | GND          | Common ground             |

## Important

- **Power: 3.3V only** — the GM861-LED runs on 3.3V. 5V will damage it.
- If nothing works after scanning a QR code — **swap TX and RX**.
- Wire colors may vary by seller. **Color doesn't matter** — check the pin position on the module connector.
- Almost any GPIO works for software UART. Pins 18/19 are just a suggestion.
- Better to avoid using the pins labeled RX/TX on the ESP32-C6 board itself (they're usually tied to the USB serial and can cause conflicts).
