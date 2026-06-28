# espidf-esp32-c6-to-gm861

- [Русская версия](README_RU.md)
- [English version](README.md)
- [PDF 手册](GM861%20GM861-LED%20Barcode%20reader%20module%20User%20Manual-V1.2.4.pdf)

**ESP32-C6 + GM861-LED** — 条码扫描器通过 UART 连接示例。

<img width="704" height="339" alt="image" src="https://github.com/user-attachments/assets/3b9b8583-70c7-4d49-ae7f-bf99c5d012cc" />

---

## 接线图

详见 [WIRING.md](WIRING.md) 连接示意图。

---

## 提示

- 卖家在产品描述中说实话的概率为 **0%**
- 即使确定已设置为 UART 模式 — **仍然先扫描手册中的二维码**

  <img width="93" height="105" alt="image" src="https://github.com/user-attachments/assets/87d7571b-c698-4148-a627-7bb43d2c99ae" />

- 扫描后（模块绿灯闪烁）但无反应 — **交换 RX 和 TX 引脚**
- **颜色无关紧要** — 引脚顺序与手册一致（至少在我的版本中如此），但颜色不对应
- 供电：**3.3V**
- LED 无法简单关闭
- 几乎任何 GPIO 引脚都可用于软件 RX/TX
- **最好不要使用** 板上标有 RX/TX 的引脚
- 如果仍然不行 — 逐一扫描手册中的标准设置二维码

  <img width="596" height="186" alt="image" src="https://github.com/user-attachments/assets/99cba75c-5087-4c25-b8a3-5d7b5062ba37" />

二维码按名称列于手册中。

