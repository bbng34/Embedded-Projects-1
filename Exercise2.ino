#include <LiquidCrystal.h>

// Initialize the LiquidCrystal object with the LCD pins
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(37, 36, 35, 34, 33, 32);

// Joystick pins (analog pins)
const int joystickXPin = A8;  // Joystick X-axis
const int joystickYPin = A9;  // Joystick Y-axis

void setup() {
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
 
  // Print a welcome message to the LCD
  lcd.print("Joystick Values:");
  delay(2000);  // Display for 2 seconds
  lcd.clear();

  // Initialize serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
  // Read analog values from the joystick
  int xValue = analogRead(joystickXPin);  // Read X-axis value
  int yValue = analogRead(joystickYPin);  // Read Y-axis value
 
  // Calculate the corresponding voltage (0-5V)
  float xVoltage = (xValue / 1023.0) * 5.0;
  float yVoltage = (yValue / 1023.0) * 5.0;

  // Clear the LCD before updating values
  lcd.clear();

  // Display the X-axis analog value and voltage
  lcd.setCursor(0, 0);  // Move to the first line
  lcd.print("X: ");
  lcd.print(xValue);     // Print the X analog value
  lcd.print(" ");
  lcd.print(xVoltage, 2);  // Print the X voltage (2 decimal places)
  lcd.print("V");

  // Display the Y-axis analog value and voltage
  lcd.setCursor(0, 1);  // Move to the second line
  lcd.print("Y: ");
  lcd.print(yValue);     // Print the Y analog value
  lcd.print(" ");
  lcd.print(yVoltage, 2);  // Print the Y voltage (2 decimal places)
  lcd.print("V");

  // Optional: Print to Serial Monitor for debugging
  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print(" -> ");
  Serial.print(xVoltage);
  Serial.println(" V");

  Serial.print("Y-axis: ");
  Serial.print(yValue);
  Serial.print(" -> ");
  Serial.print(yVoltage);
  Serial.println(" V");

  // Add a small delay before refreshing the values
  delay(500);
}