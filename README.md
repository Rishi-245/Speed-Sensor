# Speed-Sensor

## Description
This Arduino-based Speed Sensor project utilizes an Ultrasonic Distance Sensor to measure the real-time speed of an object. The code employs the UltraDistSensor library for the distance sensor, Wire for communication, and LiquidCrystal_I2C for the LCD display. The system initializes components in the setup, including an LED, LCD with backlight, and Serial Monitor. The continuous loop calculates speed by taking two distance readings with a 2-second delay and triggers an LED based on whether the object is moving away, getting closer, or within an acceptable speed range. Speed readings are displayed on the LCD and Serial Monitor.
