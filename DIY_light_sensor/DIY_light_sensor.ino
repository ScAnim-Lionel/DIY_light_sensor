/*
 From Switch statement http://www.arduino.cc/en/Tutorial/SwitchCase
 created 1 Jul 2009 / modified 9 Apr 2012 by Tom Igoe 
 This example code is in the public domain
 
 The circuit:
 * photoresistor from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground
 * red, yellow green leds on pin 13, 12, 11 */

// these constants won't change. They are the
// lowest and highest readings you get from your sensor:
const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 500;    // sensor maximum, discovered through experiment

// digital I/O pins
int vert = 11;
int jaune = 12;
int rouge = 13;

void setup() {
  // initialize serial communication:
  Serial.begin(9600); 
  // initialize the digital pin as an output.
  pinMode(vert, OUTPUT);     
  pinMode(jaune, OUTPUT);     
  pinMode(rouge, OUTPUT);
  //all leds are off
  digitalWrite(vert, LOW);   // turn the LED off (LOW is the voltage level)
  digitalWrite(jaune, LOW);   // turn the LED off (LOW is the voltage level)
  digitalWrite(rouge, LOW);   // turn the LED off (LOW is the voltage level)  

}

void loop() {
  // read the sensor:

  int sensorReading = analogRead(A0);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // do something different depending on the 
  // range value:
  switch (range) {
  case 0:    // your hand is on the sensor
    Serial.println("eteint");
    digitalWrite(vert, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(jaune, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(rouge, LOW);   // turn the LED off (LOW is the voltage level)
    break;
  case 1:    // your hand is close to the sensor
    Serial.println("rouge");
    digitalWrite(vert, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(jaune, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(rouge, HIGH);   // turn the LED on (HIGH is the voltage level)
    break;
  case 2:    // your hand is a few inches from the sensor
    Serial.println("jaune");
    digitalWrite(vert, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(jaune, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(rouge, LOW);   // turn the LED off (LOW is the voltage level)
    break;
  case 3:    // your hand is nowhere near the sensor
    Serial.println("vert");
    digitalWrite(vert, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(jaune, LOW);   // turn the LED off (LOW is the voltage level)
    digitalWrite(rouge, LOW);   // turn the LED off (LOW is the voltage level)
    break;
  } 
  delay(2);        // delay in between reads for stability
}

