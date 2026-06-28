# espidf-esp32-c6-to-gm861

**ESP32-C6 + GM861-LED** — сканер штрих-кодов, пример подключения через UART.

<img width="704" height="339" alt="image" src="https://github.com/user-attachments/assets/3b9b8583-70c7-4d49-ae7f-bf99c5d012cc" />

---

## Схема подключения

Подробная схема — в файле [WIRING.md](WIRING.md).

---

## Подсказки

- Шанс того, что продаван написал правду в описании товара — **0**
- Даже если уверен, что стоит режим UART — всё равно сканируй QR из мануала

  <img width="93" height="105" alt="image" src="https://github.com/user-attachments/assets/87d7571b-c698-4148-a627-7bb43d2c99ae" />

- Если отсканировал (модуль моргнул зелёным), а ничего не происходит — поменяй пины RX/TX местами
- Помни: **цвета значения не имеют**
- Порядок соответствует мануалу (по крайней мере в моей версии), а вот цвета — уже нет

  <img width="610" height="231" alt="image" src="https://github.com/user-attachments/assets/46bc37f9-53e2-4cc1-9827-affc38f5f629" />

- Питание: **3.3V**
- Нет, LED просто так не отключить
- Да, почти любые пины подойдут под программный RX/TX
- Лучше **не вешать** на те, что указаны на плате как RX/TX
- Если всё ещё не идёт — бери QR из мануала и вводи все по очереди для стандартных настроек

  <img width="596" height="186" alt="image" src="https://github.com/user-attachments/assets/99cba75c-5087-4c25-b8a3-5d7b5062ba37" />

QR по названиям найдёте в мануале.

---

## Сборка и прошивка

```bash
idf.py set-target esp32c6
idf.py build
idf.py flash monitor
```

---

## Ссылки

- [English version](README.md)
- [中文版](README_CN.md)
- [PDF-мануал](GM861%20GM861-LED%20Barcode%20reader%20module%20User%20Manual-V1.2.4.pdf)
