#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(123);

int joyX = A0;
int joyY = A1;
int joyBtn = 2;

void setup() {
  delay(1000); 
  Serial.begin(9600);
  pinMode(joyBtn, INPUT_PULLUP);

  if (!accel.begin()) {
    Serial.println("No ADXL345 detected!");
    while (1);
  }

  accel.setRange(ADXL345_RANGE_16_G);
}

void loop() {
  sensors_event_t event;
  accel.getEvent(&event);

  float x = event.acceleration.x;
  float y = event.acceleration.y;
  const float threshold = 3.0;

  if (x < -threshold) Serial.println("LEFT");
  else if (x > threshold) Serial.println("RIGHT");

  if (y < -threshold) Serial.println("UP");
  else if (y > threshold) Serial.println("DOWN");

  
  int jY = analogRead(joyY);
  if (jY < 400) Serial.println("FIRE");
  else if (jY > 600) Serial.println("RELOAD");

  if (digitalRead(joyBtn) == LOW) Serial.println("JUMP");

  delay(100);  
}
