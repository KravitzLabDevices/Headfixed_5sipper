/**
     """
  Move the servo motor to the specified spout position.

  Parameters:
  num (int): the spout position to move the servo to, from 0 to 4.

  Returns:
  None

  """
*/

void spoutPosition(int num) {
  retract();

  if (num == 1) {
    target = 0 + offset;
    analogWrite (A0, 0);
  }
  if (num == 2) {
    target = 37 + offset;
    analogWrite (A0, 250);
  }
  if (num == 3) {
    target = 74 + offset;
    analogWrite (A0, 500);
  }
  if (num == 4) {
    target = 117 + offset;
    analogWrite (A0, 750);
  }
  if (num == 5) {
    target = 160 + offset;
    analogWrite (A0, 1000);
  }

  servo_rotate.attach(10);  // attach servo to pin
  if (servo_rotate.read() > target) {
    for (pos = servo_rotate.read(); pos >= target; pos -= 1) {
      servo_rotate.write(pos);  // move servo to new position
      delay(20);                // wait for servo to move
    }
  } else {
    for (pos = servo_rotate.read(); pos <= target; pos += 1) {
      servo_rotate.write(pos);  // move servo to new position
      delay(20);                // wait for servo to move
    }
  }
  servo_rotate.detach();  // detach servo from pin
  extend();
}
