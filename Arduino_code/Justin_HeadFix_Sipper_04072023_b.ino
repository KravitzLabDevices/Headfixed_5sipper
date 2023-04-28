/*
  Justin Head Fix 5 Port Sipper device
  Kravitz Lab
  March 2023
*/

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define BUTTON_A 9
#define BUTTON_B 6
#define BUTTON_C 5

// OLED display object
Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);

//user specified volume in uL
int volume = 2;

//starting from the first trial
int Trial = 1;

Servo servo_retract;  // create servo object to control a servo
Servo servo_rotate;   // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;  // variable to store the servo position
int target = 0; //variable to store the target position for spout rotation

//servo position offset
int offset = 0;
unsigned long timer = 0;

//initialize variable for randomizing spout position
int selection = 0;

int random_delay = 0;
unsigned long startTimeout = millis();

void setup() {
  servo_retract.attach(11);  // attaches the servo on pin 11 to the servo object
  servo_rotate.attach(10);   // attaches the servo on pin 10 to the servo object
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  //pinMode(D4, OUTPUT);

  // Start the I2C communication
  Wire.begin();

  // Initialize the OLED display
  Serial.begin(115200);
  delay(250); // wait for the OLED to power up
  display.begin(0x3C, true); // Address 0x3C default
  display.clearDisplay();
  display.setRotation(1);
  display.setTextColor(SH110X_WHITE);
  display.setTextSize(1);
  display.display();

  // set spout to position 0
  spoutPosition(0);

  // use buttons to set offset
  timer = millis();
  while (millis() - timer < 5000) {
    checkbuttons();
  }
}

void loop() {

  UpdateDisplay();
  selection = positionShuffle();
  spoutPosition(selection);
  noise();
  //customDelay(5000);
  timeout(2, 33);

  UpdateDisplay();
  selection = positionShuffle();
  spoutPosition(selection);
  playTone(2000, 1000);
  dispense(selection);
  //customDelay(10000);
  retract();
  timeout(2, 3); 

}
