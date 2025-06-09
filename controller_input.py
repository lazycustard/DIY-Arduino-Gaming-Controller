import serial
import pyautogui
import time

try:
    ser = serial.Serial('COM3', 9600, timeout=1)
except serial.SerialException as e:
    print(f"Could not open COM port: {e}")
    exit()

time.sleep(1) 

while True:
    try:
        line = ser.readline().decode('utf-8').strip()
        if not line:
            continue

        print(f"Received: {line}")

        if line == "LEFT":
            pyautogui.press('a')
        elif line == "RIGHT":
            pyautogui.press('d')
        elif line == "UP":
            pyautogui.press('w')
        elif line == "DOWN":
            pyautogui.press('s')
        elif line == "JUMP":
            pyautogui.press('space')
        elif line == "FIRE"
            pyautogui.press()
        elif line == "RELOAD":
            pyautogui.press('r')

    except KeyboardInterrupt:
        print("Exiting...")
        break
    except Exception as e:
        print(f"Error: {e}")
