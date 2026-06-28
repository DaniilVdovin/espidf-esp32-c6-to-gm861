# espidf-esp32-c6-to-gm861

- [Русская версия](README_RU.md)
- [中文版](README_CN.md)
- [PDF manual](GM861%20GM861-LED%20Barcode%20reader%20module%20User%20Manual-V1.2.4.pdf)

**ESP32-C6 + GM861-LED** — barcode scanner UART connection example.

<img width="704" height="339" alt="image" src="https://github.com/user-attachments/assets/3b9b8583-70c7-4d49-ae7f-bf99c5d012cc" />

---

## Wiring

See [WIRING.md](WIRING.md) for the full connection diagram.

---

## Tips

- There's a **0% chance** the seller told the truth in the product description
- Even if you're sure UART mode is set — **still scan the QR code** from the manual first

  <img width="93" height="105" alt="image" src="https://github.com/user-attachments/assets/87d7571b-c698-4148-a627-7bb43d2c99ae" />

- If you scanned (module blinked green) but nothing happens — **swap RX and TX pins**
- **Colors don't matter** — the pin order matches the manual (at least in my version), but the colors don't
- Power: **3.3V**
- No, the LED cannot be simply disabled
- Almost any GPIO pins work for software RX/TX
- Better **not to use** the pins labeled RX/TX on the board
- If it still doesn't work — scan the QR codes from the manual one by one for standard settings

  <img width="596" height="186" alt="image" src="https://github.com/user-attachments/assets/99cba75c-5087-4c25-b8a3-5d7b5062ba37" />

QR codes are listed by name in the manual.

