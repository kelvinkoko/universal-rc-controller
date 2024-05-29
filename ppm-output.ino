#include "PPMEncoder.h"

#define OUTPUT_PIN 10

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  ppmEncoder.begin(OUTPUT_PIN);
  ppmEncoder.setChannelPercent(0, 25);
  ppmEncoder.setChannelPercent(1, 25);
}

void loop() {
  // Check if data is available in the serial buffer
  if (Serial.available() > 0) {
    // Read the input as a string
    String input = Serial.readStringUntil('\n');
    
    // Parse the input string
    int spaceIndex = input.indexOf(' ');
    if (spaceIndex > 0) {
      // Extract the percentages from the input string
      int percent0 = input.substring(0, spaceIndex).toInt();
      int percent1 = input.substring(spaceIndex + 1).toInt();
      
      // Set the channel percentages
      ppmEncoder.setChannelPercent(0, percent0);
      ppmEncoder.setChannelPercent(1, percent1);
    } else {
      Serial.println("Invalid input format. Please input two numbers separated by a space.");
    }
  }
}
