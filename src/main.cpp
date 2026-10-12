#include <Arduino.h>
const int analogpin = A0;
const int led1 = 9;
const int led2 = 10;
const int led3 = 11;


// put function declarations here:


void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // Initialize serial communication at 9600 baud rate
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
   




}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(analogpin);// Read the analog value from the sensor connected to A0


  int led1Brightness = map(sensorValue, 0, 1023, 0, 255); // Map the sensor value to a brightness value for LED1
  int led2Brightness = map(abs(sensorValue - 512), 0, 512, 255, 0); // Map the absolute difference from the center value to a brightness value for LED2
  int led3Brightness = map(sensorValue, 0, 1023, 0, 255); // Map the sensor value to a brightness value for LED3

   constrain(led1Brightness, 0, 255);// Ensure the brightness values are within the valid range of 0 to 255
   constrain(led2Brightness, 0, 255);
   constrain(led3Brightness, 0, 255);

  analogWrite(led1, led1Brightness); // Write the brightness value to LED1
  analogWrite(led2, led2Brightness); // Write the brightness value to LED2
  analogWrite(led3, led3Brightness); // Write the brightness value to LED3

  Serial.print("LED1 Brightness: "); // print the brightness value of LED1 to the serial monitor
  Serial.println(led1Brightness);
  Serial.print("LED2 Brightness: ");
  Serial.println(led2Brightness);
  Serial.print("LED3 Brightness: ");
  Serial.println(led3Brightness);

  delay(100); // Delay for 100 milliseconds before the next loop iteration


}


