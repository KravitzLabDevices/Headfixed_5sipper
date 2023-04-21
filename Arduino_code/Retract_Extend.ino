void retract() {
  servo_retract.attach(11);              // attaches the servo on pin 11 to the servo object
  for (pos = servo_retract.read(); pos <= 140; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo_retract.write(pos);  // tell servo to go to position in variable 'pos'
    delay(15);                  // waits 15ms for the servo to reach the position
  }
  servo_retract.detach();  // attaches the servo on pin 9 to the servo object
}

void extend() {
  servo_retract.attach(11);  // attaches the servo on pin 11 to the servo object
  for (pos = servo_retract.read(); pos >= 25; pos -= 1) {  // goes from 180 degrees to 0 degrees
    servo_retract.write(pos);             // tell servo to go to position in variable 'pos'
    delay(15);                             // waits 15ms for the servo to reach the position
  }
  for (pos = 24; pos >= 12; pos -= 1) {  // goes from 180 degrees to 0 degrees
    servo_retract.write(pos);            // tell servo to go to position in variable 'pos'
    delay(50);                           // waits 15ms for the servo to reach the position
  }
  for (pos = 12; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
    servo_retract.write(pos);           // tell servo to go to position in variable 'pos'
    delay(100);                          // waits 15ms for the servo to reach the position
  }
  servo_retract.detach();  // attaches the servo on pin 9 to the servo object
}
