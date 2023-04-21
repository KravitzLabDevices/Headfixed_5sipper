void checkbuttons() {
  while (digitalRead (6) == LOW) {
    offset++;
    UpdateDisplay();
    int position = 0 + offset;
    servo_rotate.attach(10);  // attach servo to pin
    if (servo_rotate.read() > position) {
      for (int pos = servo_rotate.read(); pos >= position; pos -= 1) {
        servo_rotate.write(pos);  // move servo to new position
        delay(20);                // wait for servo to move
      }
    } else {
      for (int pos = servo_rotate.read(); pos <= position; pos += 1) {
        servo_rotate.write(pos);  // move servo to new position
        delay(20);                // wait for servo to move
      }
    }
    servo_rotate.detach();  // detach servo from pin
    timer = millis();
    delay (200);
  }

  while (digitalRead (5) == LOW) {
    offset--;
    UpdateDisplay();
    int position = 0 + offset;
    servo_rotate.attach(10);  // attach servo to pin
    if (servo_rotate.read() > position) {
      for (int pos = servo_rotate.read(); pos >= position; pos -= 1) {
        servo_rotate.write(pos);  // move servo to new position
        delay(20);                // wait for servo to move
      }
    } else {
      for (int pos = servo_rotate.read(); pos <= position; pos += 1) {
        servo_rotate.write(pos);  // move servo to new position
        delay(20);                // wait for servo to move
      }
    }
    servo_rotate.detach();  // detach servo from pin
    timer = millis();
    delay (200);
  }
}
