/*
  Justin Head Fix 5 Port Sipper device
  Kravitz Lab
  March 2023
*/

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <Adafruit_seesaw.h>

int32_t encoder_position;

// OLED display object
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

// Seesaw object
Adafruit_seesaw ss;

#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5

//user specified volume in uL
int volume = 1000;

//starting from the first trial
int Trial = 1;

Servo servo_retract;  // create servo object to control a servo
Servo servo_rotate;   // create servo object to control a servo
// twelve servo objects can be created on most boards


int pos = 0;  // variable to store the servo position

//servo position offet and step
int step = 40;
int offset = 0;
unsigned long timer = 0;

int pos1 = 0;
int random_delay = 0;
unsigned long startTimeout = millis();
int16_t prevPosition = 0;
unsigned long prevTime = 0;
float timeDifference = 0;
float velocity = 0;
float distance = 0;

void setup() {
  servo_retract.attach(11);  // attaches the servo on pin 11 to the servo object
  servo_rotate.attach(10);   // attaches the servo on pin 10 to the servo object
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  // Start the I2C communication
  Wire.begin();

  //initial seesaw module
  ss.begin(0x36);

  // Initialize the OLED display
  Serial.begin(115200);
  delay(250); // wait for the OLED to power up
  display.begin(0x3C, true); // Address 0x3C default
  display.clearDisplay();
  display.setRotation(1);
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.display();


  // Enable the rotary encoder
  int encoder_position = ss.getEncoderPosition();
  UpdateDisplay();

  // Seed the random number generator using noise from an unconnected analog pin
  randomSeed(analogRead(A0));

  // set servo to position 0
  position (0);

  // use buttons to set offset
  timer = millis();
  while (millis() - timer < 5000) {
    checkbuttons();
  }
}

void loop() {

  dispense(0);
  dispense(1);
  dispense(2);
  dispense(3);
  dispense(4);

  // position(0);
  //
  //
  //  position(0);
  //  delay(500);
  //  dispense(0);
  //  delay(20000);
  //
  //  position(1);
  //  delay(500);
  //  dispense(1);
  //  delay(20000);
  //
  //  position(2);
  //  delay(500);
  //  dispense(2);
  //  delay(20000);
  //
  //  position(3);
  //  delay(500);
  //  dispense(3);
  //  delay(20000);
  //
  //  position(4);
  //  delay(500);
  //  dispense(4);
  //  delay(20000);
  //
//
//  int randomNumber = random(5);
//  position(randomNumber);
//  noise();
//  delay(5000);
//  timeout(20, 30);
//
//  randomNumber = random(5);
//  position(randomNumber);
//  playTone(2000, 1000);
//  dispense(randomNumber);
//  delay(10000);
//  retract();
//  timeout(20, 30); //change this when you want to flush the solenoid after recording

}
