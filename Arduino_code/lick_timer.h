#ifndef LICK_TIMER_H
#define LICK_TIMER_H

#include <Arduino.h>

#define TOUCH_PIN 2
#define LED_PIN 9

class lick_timer {
private:
  bool timer_on;
  bool start_state;
  unsigned long lick_start;
  unsigned long lick_dur;
  unsigned long* licks_vector;  // dynamic vector allocation
  static lick_timer* instance;
  int lick_ct;
  int vec_cap;

  void handleInterrupt();
  static void handleInterruptStatic();

  void addLick(unsigned long duration);
  void cleanup_licks();

public:
  lick_timer()
    : start_state(LOW), timer_on(false), lick_start(0), lick_dur(0), licks_vector(nullptr), lick_ct(0), vec_cap(0) {}

  void boot();
  void start();
  void stop();
  bool is_running() const;
  unsigned long* get_licks(int& out_ct);
};

/// _ ALGOS
///

lick_timer* lick_timer::instance = nullptr;

void lick_timer::handleInterruptStatic() {
  if (instance) {
    instance->handleInterrupt(); // if it exists it continuously handleInterrupt()
  }
}

void lick_timer::handleInterrupt() {
  if (!timer_on) return;
  Serial.print("Start_state: ");
  Serial.println(start_state);
  if (digitalRead(TOUCH_PIN) == HIGH && start_state == LOW) { // reset lick_start if did not boot up on lick.
    lick_start = millis();
    //Serial.println("Lick!");  // record start
  } else if (digitalRead(TOUCH_PIN) == HIGH) { // if pin is high and start_state is high
    // do nothing
  } else {
    //Serial.println("millis, lick_start");
    //Serial.println(millis());
    //Serial.println(lick_start);
    lick_dur = millis() - lick_start; // calculate lick

    if (lick_dur > 0) {
      addLick(lick_dur);
    }
    start_state = digitalRead(TOUCH_PIN);
    //Serial.print("Start_state: ");
    //Serial.println(start_state);

    lick_start = millis();
  }
}

void lick_timer::addLick(unsigned long duration) {
  if (lick_ct >= vec_cap) {
    vec_cap = (vec_cap == 0) ? 10 : vec_cap * 2;
    unsigned long* new_vec = new unsigned long[vec_cap];
    for (int i = 0; i < lick_ct; ++i) {
      new_vec[i] = licks_vector[i];
    }
    delete[] licks_vector;
    licks_vector = new_vec;
    //for (int i = 0; i < 5; i++) {
    //  digitalWrite(LED_PIN, HIGH);
    //  delay(25);
    //  digitalWrite(LED_PIN, LOW);
    //}
  }

  licks_vector[lick_ct++] = duration;
}

void lick_timer::cleanup_licks() {
  delete[] licks_vector;
  licks_vector = nullptr;
  lick_ct = 0;
  vec_cap = 0;
}

void lick_timer::boot() {
  pinMode(TOUCH_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  instance = this;
}

void lick_timer::start() {
  cleanup_licks();
  lick_start = millis();
  timer_on = true;

  attachInterrupt(digitalPinToInterrupt(TOUCH_PIN), handleInterruptStatic, CHANGE);
  start_state = digitalRead(TOUCH_PIN);
  Serial.println("Timer Started.");
}

void lick_timer::stop() {
  if (digitalRead(TOUCH_PIN) == HIGH) {
    lick_dur = millis() - lick_start;
    addLick(lick_dur);
    start_state = digitalRead(TOUCH_PIN);
  }
  timer_on = false;
  Serial.println(digitalRead(TOUCH_PIN));
  detachInterrupt(digitalPinToInterrupt(TOUCH_PIN));
  Serial.println("Timer stopped.");
}

unsigned long* lick_timer::get_licks(int& out_ct) {
  out_ct = lick_ct;
  unsigned long* licks = new unsigned long[lick_ct];
  for (int i = 0; i < lick_ct; i++) {
    licks[i] = licks_vector[i];
  }
  return licks;  // Caller must free this memory
}

bool lick_timer::is_running() const {
  return timer_on;
}

#endif