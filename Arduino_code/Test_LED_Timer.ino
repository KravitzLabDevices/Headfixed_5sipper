#include <Servo.h>


// put your setup code here, to run once:
#include <Servo.h>
#include <Wire.h>

Servo servo_retract;  // Create servo object to control a servo
int pos = 0;          // Variable to store the servo position
#include "lick_timer.h"
lick_timer lickTimer;

int fix_spout(int LickCounts, unsigned long* licks) {}
bool return_licks(int& min_lick, int& mean_lick, int& max_lick) {
  int lickCount = 0;
  unsigned long* licks = lickTimer.get_licks(lickCount);
  mean_lick = 0;
  max_lick = 0;
  min_lick = 0;
  for (int i = 0; i < lickCount; i++) {
    mean_lick += licks[i];
    if (licks[i] >= max_lick) {
      max_lick = licks[i];
    }

    if (licks[i] <= min_lick) {
      min_lick = licks[i];
    }
  }
  mean_lick = mean_lick / lickCount;
}
static int spout_set = 0;
void setup() {
  Serial.begin(9600);
  lickTimer.boot();  // Initialize lick_timer
  servo_retract.attach(11);
}

void loop() {
  // Start the lick timer
  // 5-second loop for counting
  while (spout_set != 1) {
    // lickTimer does all the work
    lickTimer.start();
    delay(5000);
    lickTimer.stop();

    int mean_lick;
    int max_lick;
    int min_lick;
    int lickCount;
    unsigned long* licks = lickTimer.get_licks(lickCount);
    return_licks(min_lick, mean_lick, max_lick);
    if (lickCount == 0){ // no licks detected
      Serial.println("Forward.");
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
    }
    else if (max_lick >= 1000){ // long lick detected
      Serial.println("Backward.");
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
    }
    else if (min_lick == max_lick){ // case: one or fewer licks, unless they were all exactly the same (very unlikely)
      Serial.println("One lick. Special case?");
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
    }
    else if (mean_lick <= 100){  // mean licking is occurring regularly and not too long, set spout. 
      spout_set = 1;
      Serial.println("Set.");
    }
    // INFO DUMP
    Serial.print("Licks Counted: ");
    Serial.println(lickCount);
    for (int i = 0; i < lickCount; i++) {
      Serial.print("Lick Duration ");
      Serial.print(i);
      Serial.print(": ");
      Serial.println(licks[i]);
    }
    
  }
}
