// Speed Sensor by Rishi

// Required Libraries
#include<UltraDistSensor.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

// Variables
UltraDistSensor mysensor;
float reading, reading2, speedms;

// SetUp Code
void setup() {
    pinMode(13, OUTPUT);           // Initializing the LED
    lcd.begin();                                // Initializing the LCD 
    lcd.backlight();                          // LCD Backlight
    Serial.begin(9600);                  // Initializing the Serial Monitor
    mysensor.attach(8,9);             // Identifying Pins (Trigger pin, Echo pin)
}

// Continuous Loop Code
void loop() {                                 
    reading=mysensor.distanceInCm();             // Distance 1 from Ultrasonic Sensor
    delay(2000);                                                    // 2 Second Delay
    reading2=mysensor.distanceInCm();          // Distance 2 from Ultrasonic Sensor
    speedms = ((reading2-reading)/2)/100;    // Speed Calculation
    
    // LED Setup Code
    if (speedms > 0.20) {
      // If speed is greater than limit of 0.30 m/s, LED lights up
      // Positive Speed = object going away from sensor
      digitalWrite(13, HIGH);
    }
    

else if (speedms < -0.20) {
     // If speed is greater than the limit of 0.30 m/s, LED lights up
     // Negative Speed = object getting closer to sensor
      digitalWrite(13, HIGH); 
    }
  
  else {
      // If speed is under the limit of 0.30 m/s, LED stays off
      digitalWrite(13,LOW);
    }

     Serial.print(speedms);         // Printing the speed in serial monitor
     lcd.setCursor(0,0);               // Sets LCD y value at y = 0
     lcd.print("Speed : ");           // Displaying the speed text on the LCD             
     lcd.setCursor(0,1);              // Sets LCD y value at y = 1
     lcd.print(speedms);            // Gets value from speed calculation and displays on LCD
     lcd.print(" m/s");   

              // Displaying the unit of measurements (m/s) on the LCD

    delay(500);                          // Half-a-second delay between each set of calculations
}
