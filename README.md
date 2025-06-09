# 🎮 DIY-Arduino-Gaming-Controller

This project transforms an Arduino into a custom game controller using motion and joystick input. It integrates an **ADXL345 accelerometer** for tilt-based directional control and a **joystick module** for additional actions like jumping and firing. A **Python script** reads input from the Arduino via serial communication and simulates keyboard and mouse events for seamless PC gameplay.

---

## 🚀 Features

| Action          | Input Component         | Mapped Key/Action |
| --------------- | ----------------------- | ----------------- |
| Move Left/Right | Tilt ADXL345 (X-axis)   | `A` / `D`         |
| Move Up/Down    | Tilt ADXL345 (Y-axis)   | `W` / `S`         |
| Fire            | Joystick pushed up      | Left Mouse Click  |
| Reload          | Joystick pushed down    | `R`               |
| Jump            | Joystick button pressed | `SPACE`           |

---

## 🧰 Hardware Required

* Arduino Uno (or compatible board)
* ADXL345 Accelerometer (I2C)
* Joystick module (X, Y, and button)
* Jumper wires
* Breadboard

---

## 🔌 Wiring Guide

### ADXL345 (I2C)

| ADXL345 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 3.3V or 5V  |
| GND         | GND         |
| SDA         | A4          |
| SCL         | A5          |

### Joystick Module

| Joystick Pin | Arduino Pin |
| ------------ | ----------- |
| VRx (X)      | A0          |
| VRy (Y)      | A1          |
| SW (Button)  | D2          |
| GND          | GND         |
| VCC          | 5V          |

---

## ⚙️ Arduino Sketch

Upload `arduino_controller.ino` to your Arduino board.
It reads sensor data and sends it via serial.

> ⚠️ **Important:** Ensure the Python script is **not running** during upload to avoid COM port conflicts.

---

## 🐍 Python Script

This script captures serial data and simulates keyboard/mouse input.

### Installation

```bash
pip install pyserial pyautogui
```

### Usage

```bash
python controller_input.py
```

> ⚠️ Update the correct COM port in the Python script:
> `serial.Serial('COM3', 9600)` (Change `COM3` as needed)

---

## 👣 Gameplay Controls

* **Tilt left/right** – Move left/right (`A` / `D`)
* **Tilt forward/backward** – Move forward/backward (`W` / `S`)
* **Push joystick up** – Fire / Tap (Left Mouse Click)
* **Push joystick down** – Reload (`R`)
* **Press joystick button** – Jump (`SPACE`)

---

## 🛠️ Troubleshooting

### 🔧 Serial/COM Port Not Found?

* Windows: Check *Device Manager*
* Linux/Mac: Run `ls /dev/tty*`

Make sure the COM port in `controller_input.py` matches your Arduino.

### ❌ Upload Fails?

* Close the Python script or any Serial Monitor (e.g., Arduino IDE).
---

## 📚 License

This project is open-source and free to use under the MIT License.

---
